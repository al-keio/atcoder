#! /usr/bin/env python
# coding: UTF-8
import requests
from bs4 import BeautifulSoup
import sys
import re
import os.path
import os
import shutil
from getpass import getpass
import configparser

# グローバル変数にするとラク
domain = "https://atcoder.jp"       # atcoderのドメイン
session = requests.session()        # セッション情報
c_dir = ""                          # 構築先ディレクトリ


def illegal_exit():
    shutil.rmtree(c_dir, ignore_errors=True)
    print('please try again')
    exit(1)


def http_get(url):
    response = session.get(url)
    if response.status_code != 200:
        print('cannot access the url "{}"'.format(url))
        illegal_exit()
    return response


def session_init():
    login_url = "{0}/{1}".format(domain, "login")

    # csrf_token取得
    r = session.get(login_url)
    s = BeautifulSoup(r.text, 'lxml')
    csrf_token = s.find(attrs={'name': 'csrf_token'}).get('value')

    if os.path.exists("./config.ini"):
        inifile = configparser.ConfigParser()
        inifile.read('./config.ini', 'UTF-8')
        username = inifile.get('user', 'username')
        password = inifile.get('user', 'password')
    else:
        username = input("username: ")
        password = getpass("password: ")

    # パラメータセット
    login_info = {
        "csrf_token": csrf_token,
        "username": username,
        "password": password
    }

    response = session.post(login_url, data=login_info)
    if response.url == login_url:
        print("cannot login")
        illegal_exit()


def fetch_question_urls(url):
    ret = []
    response = http_get(url)
    soup = BeautifulSoup(response.text, "html.parser")
    records = soup.find('tbody').find_all('tr')
    for record in records:
        ret.append([record.find('td').text.lower(), record.find('a')['href']])
    return ret


def dl_question_sample(url):
    response = http_get(url)
    soup = BeautifulSoup(response.text, "html.parser")

    i = 1
    while True:
        if soup.find('h3', text="入力例 {}".format(i)):
            op = soup.find('h3', text="入力例 {}".format(i)).next_sibling.text
            op.replace('\r', '')
            with open(os.path.join("sample", "{}_input.txt".format(i)), mode='w') as f:
                f.write(op)
        else:
            break
        i = i + 1

    i = 1
    while True:
        if soup.find('h3', text="出力例 {}".format(i)):
            op = soup.find('h3', text="出力例 {}".format(i)).next_sibling.text
            op.replace('\r', '')
            with open(os.path.join("sample", "{}_output.txt".format(i)), mode='w') as f:
                f.write(op)
        else:
            break
        i = i + 1


if __name__ == '__main__':
    args = sys.argv
    if len(args) != 3:
        print("usage: {} <type> <num>".format(args[0]))
        exit(0)
    if args[2] == "-":
        args[2] = ""

    session_init()

    s_dir = os.getcwd()
    b_url = "{0}/contests/{1}{2}/tasks".format(domain, args[1], args[2])
    c_dir = os.path.join(os.getcwd(), args[1], args[2])

    if os.path.isdir(c_dir):
        print("{} already exists.".format(c_dir))
        ans = input("overwrite the directory?[yN]: ")
        if ans != "y":
            exit(0)
        shutil.rmtree(c_dir)
    os.makedirs(c_dir)

    os.chdir(c_dir)
    shutil.copy(os.path.join(s_dir, "sample", "CMakeLists.txt"), './')

    ql = fetch_question_urls(b_url)
    for q in ql:
        os.makedirs(os.path.join(q[0], 'sample'), exist_ok=True)
        os.chdir(q[0])
        shutil.copy(os.path.join(s_dir, "sample", "main.cpp"), './')
        shutil.copy(os.path.join(s_dir, "sample", "main_test.cpp"), './')
        dl_question_sample(domain + q[1])
        os.chdir(c_dir)


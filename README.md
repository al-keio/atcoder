# C++用atcoder環境作成スクリプト
### 問題に合わせたディレクトリ構造を作成
- 各問題用に雛形コード(main.cpp)とテストコード(main_test.cpp)を配置
- スクレイピングをしてサンプルテストをダウンロード
- main_test.cpp は ダウンロードしたテストケースを用いて，main.cppに書かれたアルゴリズムをテスト

# Installation
pipenvで仮想環境を作成
```
$ pipenv install
```
## 必要なツール
- python (pyenvによるインストール推奨)
- pipenv
- bits/stdc++.h が使えるコンパイラ
  - clion ではそのコンパイラを指定する必要がある([参考](https://pleiades.io/help/clion/how-to-switch-compilers-in-clion.html))

# 使い方

## 環境構築
```
$ pipenv run ./set.py <コンテスト名(略称)> <コンテスト番号>
```
#### いちいちユーザ・パスワードを打ちたくない人向け
```
$ cp config.ini.tmpl config.ini # set.pyにconfig.iniを読み込ませるようにする
$ vim config.ini                # ユーザ・パスワードを書く(git管理対象である.tmplに書かないようにする)
```

#### パスワードが必要な理由
コンテスト中の問題は参加者しかアクセスできない  
そのため，atocoderにログインする必要がある  
ちなみに，コンテスト中じゃないコンテストのダウンロードする場合はユーザ・パスワードは適当でもよい  

### 使用例
#### 例1. AtCoder Beginner Contest 111 用の環境作成
`./abc/111/`に環境が作成される
```
$ pipenv run ./set.py abc 111 
``` 

#### 例2. AtCoder Grand Contest 024 用の環境作成
`./agc/024/`に環境が作成される
```
$ pipenv run ./set.py agc 024
```

#### 例3. AtCoder DP まとめコンテスト用の環境作成
`./dp/`に環境が作成される
```
$ pipenv run ./set.py dp -
``` 

※ 第2引数に回数を書くがdpコンテストのような単発コンテストの場合は第2引数をハイフン`-`にする

**引数はコンテストのurlを見比べてパターンを理解してほしい**- 

## 問題を解く時
1. main.cppのvoid solve()関数にアルゴリズムを書く
2. main.cppをコピー・提出する
    - web上で提出

### Clionを使う(推奨)
1. Clionのプロジェクトツリーから該当コンテストのディレクトリにあるCMakeLists.txtを右クリック
2. Load Cmake Projectをクリック
3. 右上に`<問題番号>`と`<問題番号>_test`がconfigurationに出現
- CMakeはsampleに書いてあるので書かなくてよい

### ターミナル上でテストコードを作動させる
対象のディレクトリ上で以下を実行(多分，インストールしたコンパイラは g++-9 になるはず．．．)
```
$ g++-9 ./main_test.cpp # 相対パスか絶対パスで書く

$ g++-9 main_test.cpp # <- セグフォする
```

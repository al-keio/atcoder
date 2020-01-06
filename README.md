# C++用atcoderテストコード自動生成
- C++用のatcoderの環境作成スクリプト
- 問題に合わせたディレクトリ構造を作成
  - 各問題用に雛形コードとテストコードを配置
  - スクレイピングをしてサンプルテストをダウンロード
  - テストコード上でサンプルテストを検証
- CMakeで書かれているので**Clion**で使うこと推奨

# 使い方

環境構築
```
$ pipenv run ./set.py <コンテスト名(略称)> <コンテスト番号>
```

## 使用例
### 例1. AtCoder Beginner Contest 111 用の環境作成
`./abc/111/`に環境が作成される
```
$ pipenv run ./set.py abc 111 
``` 

### 例2. AtCoder Grand Contest 024 用の環境作成
`./agc/024/`に環境が作成される
```
$ pipenv run ./set.py agc 024
```

### 例3. AtCoder DP まとめコンテスト用の環境作成
`./dp/`に環境が作成される
```
$ pipenv run ./set.py dp -
``` 

※ 第2引数に回数を書くがdpコンテストのような単発コンテストの場合は第2引数をハイフン`-`にする


# Installation
pipenvで仮想環境を作成
```
$ pipenv install
```
## 必要なツール
- python (pyenvによるインストール推奨)
- pipenv


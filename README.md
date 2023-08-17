(最近はWineでも特に問題ないみたいなので、用済みかもこれ)
 
# wrun 

Wine向けバッチファイルもどきです。  
Windowsネイティブでは全く無意味なものですが、  
Wineでバッチファイルから起動してくれない問題とか  
引数のパースが変でコケる問題を回避するために使えます。  


## 使い方 

wrunを引数なしで実行すると、カレントディレクトリの  
wrun.run に書かれているコマンドを行毎に実行します。  

引数を指定すると、それに .run を付加したファイルが対象になります。  


## 再ビルドしたいとき 

Windowsでは、 MSYS2 MingW x86 のが手っ取り早い。  
make.sh だけで済む。  

最近のMSVCではANSI文字列引数が使えなくなったので使用不可です。  
どうしてもというなら、 system() の代わりにCreateProcess()  
とかで頑張って(めんどい)  


## ライセンス 

どうでもいいので、あとは御勝手に方式。  

---
NullPopPo Lab.  

(Twitter) https://twitter.com/NullPopPoLab  
(GitHub) https://github.com/NullPopPoLab  

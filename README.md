# seg14Display8

*Ghz2000製 14セグ表示器 のサンプルソースコードです｡*


![14Seg display](https://i1.wp.com/ghz2000.com/wordpress/wp-content/uploads/2015/07/IMG_4631-e1438271456367.jpg?w=1168 "14Seg Display for Arduino")


Arduino から SPIを使ったシリアル転送で表示できる 14セグ8桁 表示器 を作りました｡
ちょっとレトロな感じのする表示器です｡
Arduino のライブラリを作ったので､アルファベットが簡単に表示できます｡


これはArduino用のサンプルスケッチになっています｡  
ライブラリ化してあるので､そこだけインポートして使用することが出来ます｡

動作確認済み｡ 記号も出せます｡

一度に読み込めるテキストは30文字です｡
それを超えると変な文字が表示されます｡

くわしくはこちらを御覧ください
http://ghz2000.com/wordpress/?p=665


mbed 版ライブラリもあります｡
https://developer.mbed.org/users/ghz2000/code/libSeg14Display/

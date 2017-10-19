# Codeforces Round #439 (Div. 2)
- [Standing: 1249](http://codeforces.com/contest/869/standings/participant/14133497#p14133497)
- Solved: 2
- TLE: 1

## [pA:The Artful Expedient](http://codeforces.com/contest/869/problem/A)
模擬，沒有太多技巧，照題目寫就AC了。

## [pB:The Eternal Immortality](http://codeforces.com/contest/869/problem/B)
基本數論，求b!/a!的個位數，就 k*(k+1)%10 = ((k%10)*(k+1)%10)%10。

## [pE:The Untended Antiquity](http://codeforces.com/contest/869/problem/E)
這題看起來像是走迷宮，可是不太會處理判斷是不是被包起來的部份。
目前作法是把陣列大小兩邊各自*2，奇數存長方形的邊，然後bfs，不意外的TLE了。
直覺上可以把判斷是否被長方形擋住可以類推成線段樹的單點查詢，可是這樣對於每個行列都要建一個線段樹，感覺怪怪的？

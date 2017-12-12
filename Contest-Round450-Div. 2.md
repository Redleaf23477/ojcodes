Educational Codeforces Round 34 (Rated for Div. 2) 
=================
- [Standing: 505](http://codeforces.com/contest/903/standings/page/26) 還在異動中
- Solved: 4

## (A. Hungry Student Problem)[http://codeforces.com/contest/903/problem/A]
Brute Force: 超級水題，是否存在(a, b)使得 3a+7b = 輸入

## (B. The Modcrab)[http://codeforces.com/contest/903/problem/B]
implementation, Brute Force, 爛解法：硬上，如果可以一擊幹死敵人就砍，else if 被打不會死就砍, else 回血。
greedy(吧？）: 算出幹掉敵人最少要砍m刀跟補n次血，然後一口氣補n次血再砍m刀
然後這題手殘我寫好久，不然可以更前面的說QQ

## (C. Boxes Packing)[http://codeforces.com/contest/903/problem/C]
離散化, implementation：數字範圍到10^9，可是只有5000個數字。

## (D. Almost Difference)[http://codeforces.com/contest/903/problem/D]
維護後綴合。

## (E. Swapping Characters)[http://codeforces.com/contest/903/problem/E]
題目給一堆字串，問說存不存在一個字串滿足對調兩個字元就可以組出題目給的字串們。
我的想法：找兩個字串（我找第0個跟第rand個），紀錄兩個字串不同的字元的索引值（如果數量==1 or > 4，代表沒救）。枚舉任兩個索引值，在str[0]把他們對調，然後檢查這個是不是合法的解。
不過wa掉了，初步推估問題出在找第0個跟第rand個這裡。

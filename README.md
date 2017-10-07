# PAT-Basic-Answers
PAT基础试题解析
# Q1001：害死人不偿命的(3n+1)猜想
## 卡拉兹(Callatz)猜想：
对任何一个自然数n，如果它是偶数，那么把它砍掉一半；如果它是奇数，那么把(3n+1)砍掉一半。这样一直反复砍下去，最后一定在某一步得到n=1。卡拉兹在1950年的世界数学家大会上公布了这个猜想，传说当时耶鲁大学师生齐动员，拼命想证明这个貌似很傻很天真的命题，结果闹得学生们无心学业，一心只证(3n+1)，以至于有人说这是一个阴谋，卡拉兹是在蓄意延缓美国数学界教学与科研的进展……<br>
我们今天的题目不是证明卡拉兹猜想，而是对给定的任一不超过1000的正整数n，简单地数一下，需要多少步（砍几下）才能得到n=1？<br>
**输入格式：** <br>
每个测试输入包含1个测试用例，即给出自然数n的值。<br>
**输出格式：**<br>
输出从n计算到1需要的步数。<br>
**输入样例：**  
3<br>
**输出样例：**  
5<br>
### 代码一（运算超时待解决）
```
#include <iostream>
using namespace std;
int count(int n)
{
    int step = 1;
    while (n != 0)
    {n=(n%2)? (3*n +1)/2 : n /= 2;step++;}
    return step;
}
int main()
{
    int n;
    cin >> n;
    cout << count(n);
    return 0;
}
```
### 代码二（编译通过）
```
#include <iostream>
using namespace std;
int main() {
    int n,step = 0;
    cin >> n;
    while (n!=1) {
        if(n%2 == 0)
        {
            n = n/2;
        }
        else
        {
            n = (3*n + 1)/2;
        }
        ++step;
    }
    cout<<step<<endl;
    return 0;
}
```
# Q1002：写出这个数
读入一个自然数n，计算其各位数字之和，用汉语拼音写出和的每一位数字。<br>
**输入格式：** <br>
每个测试输入包含1个测试用例，即给出自然数n的值。这里保证n小于10100。<br>
**输出格式：** <br>
在一行内输出n的各位数字之和的每一位，拼音数字间有1 空格，但一行中最后一个拼音数字后没有空格。<br>
**输入样例：**  
1234567890987654321123456789<br>
**输出样例：**  
yi san wu<br>
### 代码：
```
#include<iostream>
using namespace std;


void int_pinyin(int a){
	switch(a){
		case 0:cout<<"ling";break;
		case 1:cout<<"yi";break;
		case 2:cout<<"er";break;
		case 3:cout<<"san";break;
		case 4:cout<<"si";break;
		case 5:cout<<"wu";break;
		case 6:cout<<"liu";break;
		case 7:cout<<"qi";break;
		case 8:cout<<"ba";break;
		case 9:cout<<"jiu";break;	
	}
}
int main()
{
char a[101];
cin>>a;
int sum=0,i=0;
while(a[i]!='\0'){
	sum+=a[i]-'0';
	++i;
}
int b[11],j=0;
if(sum==0){
	int_pinyin(0);
	return 0;
}
while(sum!=0){
	b[j]=sum%10;
	sum=sum/10;
	++j;
}
for(int i=j-1;i>0;--i){
	int_pinyin(b[i]);
	cout<<" ";
}
int_pinyin(b[0]);
return 0;
} 
```
# Q1003：我要通过！
“答案正确”是自动判题系统给出的最令人欢喜的回复。本题属于PAT的“答案正确”大派送 —— 只要读入的字符串满足下列条件，系统就输出“答案正确”，否则输出“答案错误”。得到“答案正确”的条件是：<br>
1. 字符串中必须仅有P, A, T这三种字符，不可以包含其它字符；<br>
2. 任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；<br>
3. 如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a, b, c 均或者是空字符串，或者是仅由字母 A 组成的字符串。<br>
现在就请你为PAT写一个自动裁判程序，判定哪些字符串是可以获得“答案正确”的。<br>
**输入格式：** <br>
每个测试输入包含1个测试用例。第1行给出一个自然数n (<10)，是需要检测的字符串个数。接下来每个字符串占一行，字符串长度不超过100，且不包含空格。<br>
**输出格式：**<br>
每个字符串的检测结果占一行，如果该字符串可以获得“答案正确”，则输出YES，否则输出NO。<br>
**输入样例：**  
APAAATAA<br>
**输出样例：**  
NO
### 代码
# Q1004：成绩排名
读入n名学生的姓名、学号、成绩，分别输出成绩最高和成绩最低学生的姓名和学号。<br>
**输入格式：** <br>
每个测试输入包含1个测试用例，格式为<br>
  第1行：正整数n<br>
  第2行：第1个学生的姓名 学号 成绩<br>
  第3行：第2个学生的姓名 学号 成绩<br>
  ... ... ...<br>
  第n+1行：第n个学生的姓名 学号 成绩<br>
其中姓名和学号均为不超过10个字符的字符串，成绩为0到100之间的一个整数，这里保证在一组测试用例中没有两个学生的成绩是相同的。<br>
**输出格式：**<br>
对每个测试用例输出2行，第1行是成绩最高学生的姓名和学号，第2行是成绩最低学生的姓名和学号，字符串间有1空格。<br>
**输入样例：**  
3<br>
Joe Math990112 89<br>
Mike CS991301 100<br>
Mary EE990830 95<br>
**输出样例：**  
Mike CS991301<br>
Joe Math990112
### 代码
```
#include <iostream>
#include <algorithm>

using namespace std;

struct node
{
 char name[20];
 char number[20];
 int score;
}student[105];
  
int main()
{
  int i;
  int max=0,min=0;
 int n;
  cin>>n;
  for(i=0;i<n;i++)
  {
    cin>>student[i].name;
    cin>>student[i].number;
     cin>>student[i].score;
  }
  for(i=0;i<n;i++)
  {
    if(student[i].score>student[max].score)
      max=i;
    if(student[i].score<student[min].score)
      min=i;
  }
  cout<<student[max].name<<" "<<student[max].number<<endl;
  cout<<student[min].name<<" "<<student[min].number<<endl;
  return 0;
}
```
# Q1005：继续(3n+1)猜想
卡拉兹(Callatz)猜想已经在1001中给出了描述。在这个题目里，情况稍微有些复杂。<br>
当我们验证卡拉兹猜想的时候，为了避免重复计算，可以记录下递推过程中遇到的每一个数。例如对n=3进行验证的时候，我们需要计算3、5、8、4、2、1，则当我们对n=5、8、4、2进行验证的时候，就可以直接判定卡拉兹猜想的真伪，而不需要重复计算，因为这4个数已经在验证3的时候遇到过了，我们称5、8、4、2是被3“覆盖”的数。我们称一个数列中的某个数n为“关键数”，如果n不能被数列中的其他数字所覆盖。<br>
现在给定一系列待验证的数字，我们只需要验证其中的几个关键数，就可以不必再重复验证余下的数字。你的任务就是找出这些关键数字，并按从大到小的顺序输出它们。<br>
**输入格式：** <br>
每个测试输入包含1个测试用例，第1行给出一个正整数K(<100)，第2行给出K个互不相同的待验证的正整数n(1<n<=100)的值，数字间用空格隔开。<br>
**输出格式：** <br>
每个测试用例的输出占一行，按从大到小的顺序输出关键数字。数字间用1个空格隔开，但一行中最后一个数字后没有空格。<br>
**输入样例：**  
6<br>
3 5 6 7 8 11<br>
**输出样例：**  
7 6<br>
### 代码：
# Q1006：换个格式输出整数
让我们用字母B来表示“百”、字母S表示“十”，用“12...n”来表示个位数字n（<10），换个格式来输出任一个不超过3位的正整数。例如234应该被输出为BBSSS1234，因为它有2个“百”、3个“十”、以及个位的4。<br>
**输入格式：** <br>
每个测试输入包含1个测试用例，给出正整数n（<1000）。<br>
**输出格式：** <br>
每个测试用例的输出占一行，用规定的格式输出n。<br>
**输入样例：**  
234<br>
23<br>
**输出样例：**  
BBSSS1234<br>
SS123<br>
### 代码：
# Q1007：素数对猜想
让我们定义 dn 为：dn = pn+1 - pn，其中 pi 是第i个素数。显然有 d1=1 且对于n>1有 dn 是偶数。“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。现给定任意正整数N (< 105)，请计算不超过N的满足猜想的素数对的个数。<br>
**输入格式：** <br>
每个测试输入包含1个测试用例，给出正整数N。<br>
**输出格式：** <br>
每个测试用例的输出占一行，不超过N的满足猜想的素数对的个数。<br>
**输入样例：**  
20<br>
**输出样例：**  
4<br>
### 代码：
# Q1008：数组元素循环右移问题
一个数组A中存有N（N>0）个整数，在不允许使用另外数组的前提下，将每个整数循环向右移M（M>=0）个位置，即将A中的数据由（A0 A1……AN-1）变换为（AN-M …… AN-1 A0 A1……AN-M-1）（最后M个数循环移至最前面的M个位置）。如果需要考虑程序移动数据的次数尽量少，要如何设计移动的方法？<br>
**输入格式：** <br>
每个输入包含一个测试用例，第1行输入N ( 1<=N<=100)、M（M>=0）；第2行输入N个整数，之间用空格分隔。<br>
**输出格式：** <br>
在一行中输出循环右移M位以后的整数序列，之间用空格分隔，序列结尾不能有多余空格。<br>
**输入样例：**  
6 2<br>
1 2 3 4 5 6<br>
**输出样例：**  
5 6 1 2 3 4<br>
### 代码：
# Q1009：说反话
给定一句英语，要求你编写程序，将句中所有单词的顺序颠倒输出。<br>
**输入格式：** <br>
测试输入包含一个测试用例，在一行内给出总长度不超过80的字符串。字符串由若干单词和若干空格组成，其中单词是由英文字母（大小写有区分）组成的字符串，单词之间用1个空格分开，输入保证句子末尾没有多余的空格。<br>
**输出格式：** <br>
每个测试用例的输出占一行，输出倒序后的句子。。<br>
**输入样例：**  
Hello World Here I Come<br>
**输出样例：**  
Come I Here World Hello<br>
### 代码：
# Q1010：一元多项式求导
设计函数求一元多项式的导数。（注：xn（n为整数）的一阶导数为n*xn-1。）<br>
**输入格式：** <br>
以指数递降方式输入多项式非零项系数和指数（绝对值均为不超过1000的整数）。数字间以空格分隔。<br>
**输出格式：** <br>
以与输入相同的格式输出导数多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。注意“零多项式”的指数和系数都是0，但是表示为“0 0”。<br>
**输入样例：**  
3 4 -5 2 6 1 -2 0<br>
**输出样例：**  
12 3 -10 1 6 0<br>
### 代码：
# Q1011：A+B和C
给定区间[pow(-2,31),pow(2,31)]内的3个整数A、B和C，请判断A+B是否大于C。<br>
**输入格式：** <br>
输入第1行给出正整数T(<=10)，是测试用例的个数。随后给出T组测试用例，每组占一行，顺序给出A、B和C。整数间以空格分隔。<br>
**输出格式：** <br>
对每组测试用例，在一行中输出“Case #X: true”如果A+B>C，否则输出“Case #X: false”，其中X是测试用例的编号（从1开始）。<br>
**输入样例：**  
4<br>
1 2 3<br>
2 3 4<br>
2147483647 0 2147483646<br>
0 -2147483648 -2147483647<br>
**输出样例：**  
Case #1: false<br>
Case #2: true<br>
Case #3: true<br>
Case #4: false<br>
### 代码一：
```
#include <iostream>

using namespace std;

int main()
{
    long int A,B,C; //注意范围所以用long int定义A,B,C;
    
    int i;
    
    int T;
    
    cin>>T;

    for(i=1;i<=T;i++)
    {
        cin>>A>>B>>C;
        
        if(A+B>C)
        {
            cout<<"Case #"<<i<<": true"<<endl;
        }
        else
        {
            cout<<"Case #"<<i<<": false"<<endl;
        }
    }
    
    return 0;
}
```
### 代码二：
```
#include <iostream>

using namespace std;

int main()
{
    long int A,B,C;
    
    int T;
    
    int X=1;
    
    cin>>T;
    
    while(T--)
    {
      cin>>A>>B>>C;
      if(A+B>C)
      cout<<"Case #"<<X++<<": true"<<endl;   
      else
      cout<<"Case #"<<X++<<": false"<<endl;     
                           
    }
    return 0;
}
```
# Q1012：数字分类
给定一系列正整数，请按要求对数字进行分类，并输出以下5个数字：
* A1 = 能被5整除的数字中所有偶数的和；
* A2 = 将被5除后余1的数字按给出顺序进行交错求和，即计算n1-n2+n3-n4...；
* A3 = 被5除后余2的数字的个数；
* A4 = 被5除后余3的数字的平均数，精确到小数点后1位；
* A5 = 被5除后余4的数字中最大数字。<br>
**输入格式：** <br>
每个输入包含1个测试用例。每个测试用例先给出一个不超过1000的正整数N，随后给出N个不超过1000的待分类的正整数。数字间以空格分隔。<br>
**输出格式：** <br>
对给定的N个正整数，按题目要求计算A1~A5并在一行中顺序输出。数字间以空格分隔，但行末不得有多余空格。<br>
若其中某一类数字不存在，则在相应位置输出“N”。<br>
**输入样例：**  
13 1 2 3 4 5 6 7 8 9 10 20 16 18<br>
8 1 2 4 5 6 7 9 16<br>
**输出样例：**  
30 11 2 9.7 9<br>
N 11 2 N 9<br>
### 代码：
```
```
# Q1013：数素数
令Pi表示第i个素数。现任给两个正整数M <= N <= pow(10,4)，请输出PM到PN的所有素数。<br>
**输入格式：** <br>
输入在一行中给出M和N，其间以空格分隔。<br>
**输出格式：** <br>
输出从PM到PN的所有素数，每10个数字占1行，其间以空格分隔，但行末不得有多余空格。<br>
**输入样例：**  
5 27<br>
**输出样例：**  
11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97 101 103<br>
### 代码：
```
```
# Q1014：福尔摩斯的约会
大侦探福尔摩斯接到一张奇怪的字条：“我们约会吧！ 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm”。大侦探很快就明白了，字条上奇怪的乱码实际上就是约会的时间“星期四 14:04”，因为前面两字符串中第1对相同的大写英文字母（大小写有区分）是第4个字母'D'，代表星期四；第2对相同的字符是'E'，那是第5个英文字母，代表一天里的第14个钟头（于是一天的0点到23点由数字0到9、以及大写字母A到N表示）；后面两字符串第1对相同的英文字母's'出现在第4个位置（从0开始计数）上，代表第4分钟。现给定两对字符串，请帮助福尔摩斯解码得到约会的时间。<br>
**输入格式：** <br>
输入在4行中分别给出4个非空、不包含空格、且长度不超过60的字符串。<br>
**输出格式：** <br>
在一行中输出约会的时间，格式为“DAY HH:MM”，其中“DAY”是某星期的3字符缩写，即MON表示星期一，TUE表示星期二，WED表示星期三，THU表示星期四，FRI表示星期五，SAT表示星期六，SUN表示星期日。题目输入保证每个测试存在唯一解。<br>
**输入样例：**  
3485djDkxh4hhGE <br>
2984akDfkkkkggEdsb <br>
s&hgsfdk <br>
d&Hyscvnm<br>
**输出样例：**  
THU 14:04<br>
### 代码：
```
```
# Q1015：德才论
宋代史学家司马光在《资治通鉴》中有一段著名的“德才论”：“是故才德全尽谓之圣人，才德兼亡谓之愚人，德胜才谓之君子，才胜德谓之小人。凡取人之术，苟不得圣人，君子而与之，与其得小人，不若得愚人。”现给出一批考生的德才分数，请根据司马光的理论给出录取排名。<br>
**输入格式：** <br>
输入第1行给出3个正整数，分别为：N（<=105），即考生总数；L（>=60），为录取最低分数线，即德分和才分均不低于L的考生才有资格被考虑录取；H（<100），为优先录取线——德分和才分均不低于此线的被定义为“才德全尽”，此类考生按德才总分从高到低排序；才分不到但德分到线的一类考生属于“德胜才”，也按总分排序，但排在第一类考生之后；德才分均低于H，但是德分不低于才分的考生属于“才德兼亡”但尚有“德胜才”者，按总分排序，但排在第二类考生之后；其他达到最低线L的考生也按总分排序，但排在第三类考生之后。随后N行，每行给出一位考生的信息，包括：准考证号、德分、才分，其中准考证号为8位整数，德才分为区间[0, 100]内的整数。数字间以空格分隔。<br>
**输出格式：** <br>
输出第1行首先给出达到最低分数线的考生人数M，随后M行，每行按照输入格式输出一位考生的信息，考生按输入中说明的规则从高到低排序。当某类考生中有多人总分相同时，按其德分降序排列；若德分也并列，则按准考证号的升序输出。<br>
**输入样例：**  
14 60 80<br>
10000001 64 90<br>
10000002 90 60<br>
10000011 85 80<br>
10000003 85 80<br>
10000004 80 85<br>
10000005 82 77<br>
10000006 83 76<br>
10000007 90 78<br>
10000008 75 79<br>
10000009 59 90<br>
10000010 88 45<br>
10000012 80 100<br>
10000013 90 99<br>
10000014 66 60<br>
**输出样例：**  
12<br>
10000013 90 99<br>
10000012 80 100<br>
10000003 85 80<br>
10000011 85 80<br>
10000004 80 85<br>
10000007 90 78<br>
10000006 83 76<br>
10000005 82 77<br>
10000002 90 60<br>
10000014 66 60<br>
10000008 75 79<br>
10000001 64 90<br>
### 代码：
```
```
# Q1016：部分A+B
正整数A的“DA（为1位整数）部分”定义为由A中所有DA组成的新整数PA。例如：给定A = 3862767，DA = 6，则A的“6部分”PA是66，因为A中有2个6。现给定A、DA、B、DB，请编写程序计算PA + PB。<br>
**输入格式：** <br>
输入在一行中依次给出A、DA、B、DB，中间以空格分隔，其中0 < A, B < 1010。<br>
**输出格式：** <br>
在一行中输出PA + PB的值。<br>
**输入样例：**  
3862767 6 13530293 3<br>
3862767 1 13530293 8<br>
**输出样例：**  
399<br>
0<br>
### 代码：
```
```
# Q1017：A除以B
本题要求计算A/B，其中A是不超过1000位的正整数，B是1位正整数。你需要输出商数Q和余数R，使得A = B * Q + R成立。<br>
**输入格式：** <br>
输入在1行中依次给出A和B，中间以1空格分隔。<br>
**输出格式：** <br>
在1行中依次输出Q和R，中间以1空格分隔。<br>
**输入样例：**  
123456789050987654321 7<br>
**输出样例：**  
17636684150141093474 3<br>
### 代码：
```
```
# Q1018：锤子剪刀布
家应该都会玩“锤子剪刀布”的游戏：两人同时给出手势，胜负规则如图所示：现给出两人的交锋记录，请统计双方的胜、平、负次数，并且给出双方分别出什么手势的胜算最大。<br>
**输入格式：** <br>
输入第1行给出正整数N（<=105），即双方交锋的次数。随后N行，每行给出一次交锋的信息，即甲、乙双方同时给出的的手势。C代表“锤子”、J代表“剪刀”、B代表“布”，第1个字母代表甲方，第2个代表乙方，中间有1个空格。<br>
**输出格式：** <br>
输出第1、2行分别给出甲、乙的胜、平、负次数，数字间以1个空格分隔。第3行给出两个字母，分别代表甲、乙获胜次数最多的手势，中间有1个空格。如果解不唯一，则输出按字母序最小的解。<br>
**输入样例：**  
10<br>
C J<br>
J B<br>
C B<br>
B B<br>
B C<br>
C C<br>
C B<br>
J B<br>
B C<br>
J J<br>
**输出样例：**  
5 3 2<br>
2 3 5<br>
B B<br>
### 代码：
```
```
# Q1019：数字黑洞
给定任一个各位数字不完全相同的4位正整数，如果我们先把4个数字按非递增排序，再按非递减排序，然后用第1个数字减第2个数字，将得到一个新的数字。一直重复这样做，我们很快会停在有“数字黑洞”之称的6174，这个神奇的数字也叫Kaprekar常数。<br>
例如，我们从6767开始，将得到<br>
7766 - 6677 = 1089<br>
9810 - 0189 = 9621<br>
9621 - 1269 = 8352<br>
8532 - 2358 = 6174<br>
7641 - 1467 = 6174<br>
... ...<br>
现给定任意4位正整数，请编写程序演示到达黑洞的过程。<br>
**输入格式：** <br>
输入给出一个(0, 10000)区间内的正整数N。<br>
**输出格式：** <br>
如果N的4位数字全相等，则在一行内输出“N - N = 0000”；否则将计算的每一步在一行内输出，直到6174作为差出现，输出格式见样例。注意每个数字按4位数格式输出。<br>
**输入样例：**  
6767<br>
2222<br>
**输出样例：**  
7766 - 6677 = 1089<br>
9810 - 0189 = 9621<br>
9621 - 1269 = 8352<br>
8532 - 2358 = 6174<br>
2222 - 2222 = 0000<br>
### 代码：
```
```
# Q1020：月饼
月饼是中国人在中秋佳节时吃的一种传统食品，不同地区有许多不同风味的月饼。现给定所有种类月饼的库存量、总售价、以及市场的最大需求量，请你计算可以获得的最大收益是多少。注意：销售时允许取出一部分库存。样例给出的情形是这样的：假如我们有3种月饼，其库存量分别为18、15、10万吨，总售价分别为75、72、45亿元。如果市场的最大需求量只有20万吨，那么我们最大收益策略应该是卖出全部15万吨第2种月饼、以及5万吨第3种月饼，获得 72 + 45/2 = 94.5（亿元）。<br>
**输入格式：** <br>
每个输入包含1个测试用例。每个测试用例先给出一个不超过1000的正整数N表示月饼的种类数、以及不超过500（以万吨为单位）的正整数D表示市场最大需求量。随后一行给出N个正数表示每种月饼的库存量（以万吨为单位）；最后一行给出N个正数表示每种月饼的总售价（以亿元为单位）。数字间以空格分隔。<br>
**输出格式：** <br>
对每组测试用例，在一行中输出最大收益，以亿元为单位并精确到小数点后2位。<br>
**输入样例：**  
3 20<br>
18 15 10<br>
75 72 45<br>
**输出样例：**  
94.50<br>
### 代码：
```
```
# Q1021：个位数统计
给定一个k位整数N = dk-1*10k-1 + ... + d1*101 + d0 (0<=di<=9, i=0,...,k-1, dk-1>0)，请编写程序统计每种不同的个位数字出现的次数。例如：给定N = 100311，则有2个0，3个1，和1个3。<br>
**输入格式：** <br>
每个输入包含1个测试用例，即一个不超过1000位的正整数N。<br>
**输出格式：** <br>
对N中每一种不同的个位数字，以D:M的格式在一行中输出该位数字D及其在N中出现的次数M。要求按D的升序输出。<br>
**输入样例：**  
100311<br>
**输出样例：**  
0:2<br>
1:3<br>
3:1<br>
### 代码：
```
```
# Q1022：D进制的A+B 
输入两个非负10进制整数A和B(<=230-1)，输出A+B的D (1 < D <= 10)进制数。<br>
**输入格式：** <br>
输入在一行中依次给出3个整数A、B和D。<br>
**输出格式：** <br>
输出A+B的D进制数。<br>
**输入样例：**  
123 456 8<br>
**输出样例：**  
1103<br>
### 代码(部分正确18/20)：
```

#include <iostream>
#include <string>

using namespace std;

string ad(int num,int D)
{
    string i = "";
    
    while(num != 0)
    {
        i = char(num % D + '0') + i;
        num /= D;
    }
    return i;
}

int main(void)
{
    int A,B,D;
    
    cin>>A>>B>>D;
    
    cout<<ad(A+B,D)<<endl;
    
    return 0;
}
```
### 代码二：
```
#include <iostream>

using namespace std;

int main()
{
    int a,b,c,d;
    int i,n=0;
    int s[100];
    cin>>a>>b>>d;
    c=a+b;
    while (c!=0)
    {
        s[n++]=c%d;
        c=c/d;
    }
    for(i=n-1;i>=0;i--)
    {
        printf("%d",s[i]);
    }
    if(n==0)
    {
        cout<<"0"<<endl;
    }
    return 0;
}
```
# Q101：
<br>
**输入格式：** <br>
<br>
**输出格式：** <br>
<br>
**输入样例：**  
<br>
**输出样例：**  
<br>
### 代码：
```
```
# Q101：
<br>
**输入格式：** <br>
<br>
**输出格式：** <br>
<br>
**输入样例：**  
<br>
**输出样例：**  
<br>
### 代码：
```
```
# Q101：
<br>
**输入格式：** <br>
<br>
**输出格式：** <br>
<br>
**输入样例：**  
<br>
**输出样例：**  
<br>
### 代码：
```
```
# Q101：
<br>
**输入格式：** <br>
<br>
**输出格式：** <br>
<br>
**输入样例：**  
<br>
**输出样例：**  
<br>
### 代码：
```
```
# Q101：
<br>
**输入格式：** <br>
<br>
**输出格式：** <br>
<br>
**输入样例：**  
<br>
**输出样例：**  
<br>
### 代码：
```
```
# Q101：
<br>
**输入格式：** <br>
<br>
**输出格式：** <br>
<br>
**输入样例：**  
<br>
**输出样例：**  
<br>
### 代码：
```
```
# Q101：
<br>
**输入格式：** <br>
<br>
**输出格式：** <br>
<br>
**输入样例：**  
<br>
**输出样例：**  
<br>
### 代码：
```
```
# Q101：
<br>
**输入格式：** <br>
<br>
**输出格式：** <br>
<br>
**输入样例：**  
<br>
**输出样例：**  
<br>
### 代码：
```
```
# Q101：
<br>
**输入格式：** <br>
<br>
**输出格式：** <br>
<br>
**输入样例：**  
<br>
**输出样例：**  
<br>
### 代码：
```
```
# Q101：
<br>
**输入格式：** <br>
<br>
**输出格式：** <br>
<br>
**输入样例：**  
<br>
**输出样例：**  
<br>
### 代码：
```
```
# Q101：
<br>
**输入格式：** <br>
<br>
**输出格式：** <br>
<br>
**输入样例：**  
<br>
**输出样例：**  
<br>
### 代码：
```
```
# Q101：
<br>
**输入格式：** <br>
<br>
**输出格式：** <br>
<br>
**输入样例：**  
<br>
**输出样例：**  
<br>
### 代码：
```
```
# Q101：
<br>
**输入格式：** <br>
<br>
**输出格式：** <br>
<br>
**输入样例：**  
<br>
**输出样例：**  
<br>
### 代码：
```
```
# Q101：
<br>
**输入格式：** <br>
<br>
**输出格式：** <br>
<br>
**输入样例：**  
<br>
**输出样例：**  
<br>
### 代码：
```
```
# Q101：
<br>
**输入格式：** <br>
<br>
**输出格式：** <br>
<br>
**输入样例：**  
<br>
**输出样例：**  
<br>
### 代码：
```
```
# Q101：
<br>
**输入格式：** <br>
<br>
**输出格式：** <br>
<br>
**输入样例：**  
<br>
**输出样例：**  
<br>
### 代码：
```
```
# Q101：
<br>
**输入格式：** <br>
<br>
**输出格式：** <br>
<br>
**输入样例：**  
<br>
**输出样例：**  
<br>
### 代码：
```
```
# Q101：
<br>
**输入格式：** <br>
<br>
**输出格式：** <br>
<br>
**输入样例：**  
<br>
**输出样例：**  
<br>
### 代码：
```
```
# Q101：
<br>
**输入格式：** <br>
<br>
**输出格式：** <br>
<br>
**输入样例：**  
<br>
**输出样例：**  
<br>
### 代码：
```
```
# Q101：
<br>
**输入格式：** <br>
<br>
**输出格式：** <br>
<br>
**输入样例：**  
<br>
**输出样例：**  
<br>
### 代码：
```
```
# Q101：
<br>
**输入格式：** <br>
<br>
**输出格式：** <br>
<br>
**输入样例：**  
<br>
**输出样例：**  
<br>
### 代码：
```
```
# Q101：
<br>
**输入格式：** <br>
<br>
**输出格式：** <br>
<br>
**输入样例：**  
<br>
**输出样例：**  
<br>
### 代码：
```
```
# Q101：
<br>
**输入格式：** <br>
<br>
**输出格式：** <br>
<br>
**输入样例：**  
<br>
**输出样例：**  
<br>
### 代码：
```
```
# Q1046:划拳
划拳是古老中国酒文化的一个有趣的组成部分。酒桌上两人划拳的方法为：每人口中喊出一个数字，同时用手比划出一个数字。如果谁比划出的数字正好等于两人喊出的数字之和，谁就赢了，输家罚一杯酒。两人同赢或两人同输则继续下一轮，直到唯一的赢家出现。下面给出甲、乙两人的划拳记录，请你统计他们最后分别喝了多少杯酒。<br>
**输入格式：** <br>
输入第一行先给出一个正整数N（<=100），随后N行，每行给出一轮划拳的记录，格式为：甲喊 甲划 乙喊 乙划其中“喊”是喊出的数字，“划”是划出的数字，均为不超过100的正整数（两只手一起划）。<br>
**输出格式：**<br>
在一行中先后输出甲、乙两人喝酒的杯数，其间以一个空格分隔。<br>
**输入样例：** <br> 
5<br>
8 10 9 12<br>
5 10 5 10<br>
3 8 5 12<br>
12 18 1 13<br>
4 16 12 15<br>
**输出样例：**  <br>
1 2
### 代码
```
#include <iostream>

using namespace std;

int main()

{
    int times;

    int a,a2,b,b2;
    
    int i;
    
    int A=0;
    
    int B=0;
    
    cin>>times;
    
    for(i=0;i<times;i++)
        
    {
        cin>>a>>a2>>b>>b2;
        
        if(a2==a+b&&a+b!=b2)
        {
            B++;
        }
        else if(a+b!=a2&&a+b==b2)
        {
            A++;
        }
        
    }
    
    cout<<A<<" "<<B<<endl;
    return 0;
}

```
# Q101：
<br>
**输入格式：** <br>
<br>
**输出格式：** <br>
<br>
**输入样例：**  
<br>
**输出样例：**  
<br>
### 代码：
```
```
# Q101：
<br>
**输入格式：** <br>
<br>
**输出格式：** <br>
<br>
**输入样例：**  
<br>
**输出样例：**  
<br>
### 代码：
```
```
# Q101：
<br>
**输入格式：** <br>
<br>
**输出格式：** <br>
<br>
**输入样例：**  
<br>
**输出样例：**  
<br>
### 代码：
```
```
# Q101：
<br>
**输入格式：** <br>
<br>
**输出格式：** <br>
<br>
**输入样例：**  
<br>
**输出样例：**  
<br>
### 代码：
```
```
# Q101：
<br>
**输入格式：** <br>
<br>
**输出格式：** <br>
<br>
**输入样例：**  
<br>
**输出样例：**  
<br>
### 代码：
```
```
# Q101：
<br>
**输入格式：** <br>
<br>
**输出格式：** <br>
<br>
**输入样例：**  
<br>
**输出样例：**  
<br>
### 代码：
```
```
# Q101：
<br>
**输入格式：** <br>
<br>
**输出格式：** <br>
<br>
**输入样例：**  
<br>
**输出样例：**  
<br>
### 代码：
```
```
# Q101：
<br>
**输入格式：** <br>
<br>
**输出格式：** <br>
<br>
**输入样例：**  
<br>
**输出样例：**  
<br>
### 代码：
```
```
# Q101：
<br>
**输入格式：** <br>
<br>
**输出格式：** <br>
<br>
**输入样例：**  
<br>
**输出样例：**  
<br>
### 代码：
```
```
# Q101：
<br>
**输入格式：** <br>
<br>
**输出格式：** <br>
<br>
**输入样例：**  
<br>
**输出样例：**  
<br>
### 代码：
```
```
# Q101：
<br>
**输入格式：** <br>
<br>
**输出格式：** <br>
<br>
**输入样例：**  
<br>
**输出样例：**  
<br>
### 代码：
```
```
# Q101：
<br>
**输入格式：** <br>
<br>
**输出格式：** <br>
<br>
**输入样例：**  
<br>
**输出样例：**  
<br>
### 代码：
```
```
# Q101：
<br>
**输入格式：** <br>
<br>
**输出格式：** <br>
<br>
**输入样例：**  
<br>
**输出样例：**  
<br>
### 代码：
```
```
# Q101：
<br>
**输入格式：** <br>
<br>
**输出格式：** <br>
<br>
**输入样例：**  
<br>
**输出样例：**  
<br>
### 代码：
```
```
# Q101：
<br>
**输入格式：** <br>
<br>
**输出格式：** <br>
<br>
**输入样例：**  
<br>
**输出样例：**  
<br>
### 代码：
```
```
# Q101：
<br>
**输入格式：** <br>
<br>
**输出格式：** <br>
<br>
**输入样例：**  
<br>
**输出样例：**  
<br>
### 代码：
```
```
# Q101：
<br>
**输入格式：** <br>
<br>
**输出格式：** <br>
<br>
**输入样例：**  
<br>
**输出样例：**  
<br>
### 代码：
```
```
# Q101：
<br>
**输入格式：** <br>
<br>
**输出格式：** <br>
<br>
**输入样例：**  
<br>
**输出样例：**  
<br>
### 代码：
```
```
# Q101：
<br>
**输入格式：** <br>
<br>
**输出格式：** <br>
<br>
**输入样例：**  
<br>
**输出样例：**  
<br>
### 代码：
```
```
# Q101：
<br>
**输入格式：** <br>
<br>
**输出格式：** <br>
<br>
**输入样例：**  
<br>
**输出样例：**  
<br>
### 代码：
```
```
# Q101：
<br>
**输入格式：** <br>
<br>
**输出格式：** <br>
<br>
**输入样例：**  
<br>
**输出样例：**  
<br>
### 代码：
```
```
# Q101：
<br>
**输入格式：** <br>
<br>
**输出格式：** <br>
<br>
**输入样例：**  
<br>
**输出样例：**  
<br>
### 代码：
```
```
# Q101：
<br>
**输入格式：** <br>
<br>
**输出格式：** <br>
<br>
**输入样例：**  
<br>
**输出样例：**  
<br>
### 代码：
```
```
# Q101：
<br>
**输入格式：** <br>
<br>
**输出格式：** <br>
<br>
**输入样例：**  
<br>
**输出样例：**  
<br>
### 代码：
```
```
# Q101：
<br>
**输入格式：** <br>
<br>
**输出格式：** <br>
<br>
**输入样例：**  
<br>
**输出样例：**  
<br>
### 代码：
```
```
# Q101：
<br>
**输入格式：** <br>
<br>
**输出格式：** <br>
<br>
**输入样例：**  
<br>
**输出样例：**  
<br>
### 代码：
```
```
# Q101：
<br>
**输入格式：** <br>
<br>
**输出格式：** <br>
<br>
**输入样例：**  
<br>
**输出样例：**  
<br>
### 代码：
```
```
# Q101：
<br>
**输入格式：** <br>
<br>
**输出格式：** <br>
<br>
**输入样例：**  
<br>
**输出样例：**  
<br>
### 代码：
```
```
# Q101：
<br>
**输入格式：** <br>
<br>
**输出格式：** <br>
<br>
**输入样例：**  
<br>
**输出样例：**  
<br>
### 代码：
```
```
# Q101：
<br>
**输入格式：** <br>
<br>
**输出格式：** <br>
<br>
**输入样例：**  
<br>
**输出样例：**  
<br>
### 代码：
```
```
# Q101：
<br>
**输入格式：** <br>
<br>
**输出格式：** <br>
<br>
**输入样例：**  
<br>
**输出样例：**  
<br>
### 代码：
```
```

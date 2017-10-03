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

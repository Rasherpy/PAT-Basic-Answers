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
## 读入一个自然数n，计算其各位数字之和，用汉语拼音写出和的每一位数字。
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

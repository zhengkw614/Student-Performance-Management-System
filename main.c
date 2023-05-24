#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LengthMax 10  // 字符串最大长度
#define StudentNum 30 // 最大学生人数
#define CourseNum 6   // 最多课程数

int Function(void);
void ScoreGet(long num[], char name[][LengthMax],
              float score[][CourseNum], int n, int m);
void StudentAve(float score[][CourseNum], int n, int m, float sum[StudentNum], float aver[StudentNum]);
void CourseAve(float score[][CourseNum], int n, int m);
void ScoreSum(long num[], char name[][LengthMax], float score[][CourseNum], float sum[], float aver[],
              int n, int m, int (*compare)(float a, float b));
int UpSort(float a, float b);
int DownSort(float a, float b);
void SwapFloat(float *x, float *y);
void SwapLong(long *x, long *y);
void SwapChar(char x[], char y[]);
void NumUp(long num[], char name[][LengthMax],
           float score[][CourseNum], float sum[], float aver[],
           int n, int m);
void NameDictionary(long num[], char name[][LengthMax],
                    float score[][CourseNum], float sum[], float aver[],
                    int n, int m);
void NumSearch(long num[], char name[][LengthMax],
               float score[][CourseNum], float sum[], float aver[],
               int n, int m);
void NameSearch(long num[], char name[][LengthMax],
                float score[][CourseNum], float sum[], float aver[],
                int n, int m);
void Data(float score[][CourseNum], int n, int m);
void Output(long num[], char name[][LengthMax],
            float score[][CourseNum], float sum[], float aver[],
            int n, int m);
int main()
{
    char choice;
    int n = 0, m = 0;
    float score[StudentNum][CourseNum], sum[StudentNum], aver[StudentNum];
    long num[StudentNum];
    char name[StudentNum][LengthMax];
    printf("Input student number(n<30):\n", StudentNum);
    scanf("%d", &n);
    while (1) // 输出菜单选项
    {
        choice = Function();
        switch (choice)
        {
        case 1:
            printf("Input course number(m<=%d):\n", CourseNum);
            scanf("%d", &m);
            ScoreGet(num, name, score, n, m);
            break;
        case 2:
            CourseAve(score, n, m);
            break;
        case 3:
            StudentAve(score, n, m, sum, aver);
            break;
        case 4:
            ScoreSum(num, name, score, sum, aver, n, m, DownSort);
            printf("Sort in DownSort order by score:\n");
            Output(num, name, score, sum, aver, n, m);
            break;
        case 5:
            ScoreSum(num, name, score, sum, aver, n, m, UpSort);
            printf("Sort in UpSort order by score:\n");
            Output(num, name, score, sum, aver, n, m);
            break;
        case 6:
            NumUp(num, name, score, sum, aver, n, m);
            printf("Sort in UpSort order by number:\n");
            Output(num, name, score, sum, aver, n, m);
            break;
        case 7:
            NameDictionary(num, name, score, sum, aver, n, m);
            printf("Sort in dictionary order by name:\n");
            Output(num, name, score, sum, aver, n, m);
            break;
        case 8:
            NumSearch(num, name, score, sum, aver, n, m);
            break;
        case 9:
            NameSearch(num, name, score, sum, aver, n, m);
            break;
        case 10:
            Data(score, n, m);
            break;
        case 11:
            Output(num, name, score, sum, aver, n, m);
            break;
        case 0:
            printf("End of program!");
            exit(0);
        default:
            printf("Input error!\n");
        }
    }
    return 0;
}
/*
输出菜单&获取用户选择
 */
int Function(void)
{
    int itemSelected;
    printf("Management for Students' scores\n");
    printf("1.Input record\n");
    printf("2.Caculate total and average score of every course\n");
    printf("3.Caculate total and average score of every student\n");
    printf("4.Sort in DownSort order by score\n");
    printf("5.Sort in UpSort order by score\n");
    printf("6.Sort in UpSort order by number\n");
    printf("7.Sort in dictionary order by name\n");
    printf("8.Search by number\n");
    printf("9.Search by name\n");
    printf("10.Statistic analysis\n");
    printf("11.List record\n");
    printf("0.Exit\n");
    printf("Please Input your choice:\n");
    scanf("%d", &itemSelected); // 读入用户输入
    return itemSelected;
}
/*
输入n个学生的m门课成绩
*/
void ScoreGet(long num[], char name[][LengthMax],
              float score[][CourseNum], int n, int m)
{
    int i, j;
    printf("Input student's ID, name and score:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%ld%s", &num[i], name[i]);
        for (j = 0; j < m; j++)
        {
            scanf("%f", &score[i][j]);
        }
    }
}
/*
计算每个学生各门课程的总分和平均分
 */
void StudentAve(float score[][CourseNum], int n, int m,
                float sum[StudentNum], float aver[StudentNum])
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        sum[i] = 0;
        for (j = 0; j < m; j++)
        {
            sum[i] = sum[i] + score[i][j];
        }
        aver[i] = m > 0 ? sum[i] / m : -1;
        printf("student %d:sum=%.0f,aver=%.0f\n", i + 1, sum[i], aver[i]);
    }
}
/*
计算每门课程的总分和平均分
 */
void CourseAve(float score[][CourseNum], int n, int m)
{
    int i, j;
    float sum[CourseNum], aver[CourseNum];
    for (j = 0; j < m; j++)
    {
        sum[j] = 0;
        for (i = 0; i < n; i++)
        {
            sum[j] = sum[j] + score[i][j];
        }
        aver[j] = n > 0 ? sum[j] / n : -1;
        printf("course %d:sum=%.0f,aver=%.0f\n", j + 1, sum[j], aver[j]);
    }
}
/*
数组sum的元素值排序
 */
void ScoreSum(long num[], char name[][LengthMax],
              float score[][CourseNum], float sum[], float aver[],
              int n, int m, int (*compare)(float a, float b))
{
    int i, j, k, t;
    for (i = 0; i < n - 1; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
        {
            if ((*compare)(sum[j], sum[k]))
                k = j;
        }
        if (k != i)
        {
            for (t = 0; t < m; t++) // 交换m门课程的成绩
            {
                SwapFloat(&score[k][t], &score[i][t]);
            }
            SwapFloat(&sum[k], &sum[i]);   // 交换总分
            SwapFloat(&aver[k], &aver[i]); // 交换平均分
            SwapLong(&num[k], &num[i]);    // 交换学号
            SwapChar(name[k], name[i]);    // 交换姓名
        }
    }
}
/*
数据升序排序
 */
int UpSort(float a, float b)
{
    return a < b;
}
/*
数据降序排序
 */
int DownSort(float a, float b)
{
    return a > b;
}

void SwapFloat(float *x, float *y)
{
    float temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void SwapLong(long *x, long *y)
{
    long temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void SwapChar(char x[], char y[])
{
    char temp[LengthMax];
    strcpy(temp, x);
    strcpy(x, y);
    strcpy(y, temp);
}
/*
按选择法将数组num的元素值按从低到高排序
*/
void NumUp(long num[], char name[][LengthMax],
           float score[][CourseNum], float sum[], float aver[],
           int n, int m)
{
    int i, j, k, t;
    for (i = 0; i < n - 1; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
        {
            if (num[j] < num[k])
                k = j;
        }
        if (k != i)
        {
            for (t = 0; t < m; t++) /* 交换m门课程的成绩 */
            {
                SwapFloat(&score[k][t], &score[i][t]);
            }
            SwapFloat(&sum[k], &sum[i]);
            SwapFloat(&aver[k], &aver[i]);
            SwapLong(&num[k], &num[i]);
            SwapChar(name[k], name[i]);
        }
    }
}
/*
交换法实现字符串按字典顺序排序
*/
void NameDictionary(long num[], char name[][LengthMax], float score[][CourseNum],
                    float sum[], float aver[], int n, int m)
{
    int i, j, t;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(name[j], name[i]) < 0)
            {
                for (t = 0; t < m; t++)
                {
                    SwapFloat(&score[i][t], &score[j][t]);
                }
                SwapFloat(&sum[i], &sum[j]);
                SwapFloat(&aver[i], &aver[j]);
                SwapLong(&num[i], &num[j]);
                SwapChar(name[i], name[j]);
            }
        }
    }
}
/*
按学号查找
*/
void NumSearch(long num[], char name[][LengthMax],
               float score[][CourseNum], float sum[], float aver[],
               int n, int m)
{
    long number;
    int i, j;
    printf("Input the number you want to search:\n");
    scanf("%ld", &number);
    for (i = 0; i < n; i++)
    {
        if (num[i] == number)
        {
            printf("%ld\t%s\t", num[i], name[i]);
            for (j = 0; j < m; j++)
            {
                printf("%.0f\t", score[i][j]);
            }
            printf("%.0f\t%.0f\n", sum[i], aver[i]);
            return;
        }
    }
    printf("Not found!\n");
}
/*
按姓名的字典顺序排出成绩表
*/
void NameSearch(long num[], char name[][LengthMax],
                float score[][CourseNum], float sum[], float aver[],
                int n, int m)
{
    char x[LengthMax];
    int i, j;
    printf("Input the name you want to search:\n");
    scanf("%s", x);
    for (i = 0; i < n; i++)
    {
        if (strcmp(name[i], x) == 0)
        {
            printf("%ld\t%s\t", num[i], name[i]);
            for (j = 0; j < m; j++)
            {
                printf("%.0f\t", score[i][j]);
            }
            printf("%.0f\t%.0f\n", sum[i], aver[i]);
            return;
        }
    }
    printf("Not found!\n");
}
/*
统计各分数段的学生人数及所占的百分比
*/
void Data(float score[][CourseNum], int n, int m)
{
    int i, j, total, t[6];
    for (j = 0; j < m; j++)
    {
        printf("For course %d:\n", j + 1);
        memset(t, 0, sizeof(t));
        for (i = 0; i < n; i++)
        {
            if (score[i][j] >= 0 && score[i][j] < 60)
                t[0]++;
            else if (score[i][j] < 70)
                t[1]++;
            else if (score[i][j] < 80)
                t[2]++;
            else if (score[i][j] < 90)
                t[3]++;
            else if (score[i][j] < 100)
                t[4]++;
            else if (score[i][j] == 100)
                t[5]++;
        }
        for (total = 0, i = 0; i <= 5; i++)
        {
            total = total + t[i];
        }
        for (i = 0; i <= 5; i++)
        {
            if (i == 0)
                printf("<60\t%d\t%.2f%%\n", t[i], (float)t[i] / n * 100);
            else if (i == 5)
                printf("%d\t%d\t%.2f%%\n",
                       (i + 5) * 10, t[i], (float)t[i] / n * 100);
            else
                printf("%d-%d\t%d\t%.2f%%\n",
                       (i + 5) * 10, (i + 5) * 10 + 9, t[i], (float)t[i] / n * 100);
        }
    }
}
/*
输出学生成绩
*/
void Output(long num[], char name[][LengthMax],
            float score[][CourseNum], float sum[],
            float aver[], int n, int m)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        printf("%ld\t%s\t", num[i], name[i]);
        for (j = 0; j < m; j++)
        {
            printf("%.0f\t", score[i][j]);
        }
        printf("%.0f\t%.0f\n", sum[i], aver[i]);
    }
}

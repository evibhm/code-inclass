#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <process.h>

// 系统指定生命空间的大小，也即：6行；6列
const int hight = 6;
const int width = 6;

// 辅助函数1 返回一个[0, 1]的随机浮点数
double randD();
// 辅助函数2 初始化生命空间
char **init(double lifr_prob);
// 辅助函数3 释放生命空间内存
void deleteScreen(char **screen);
// 辅助函数4 打印细胞状态
void printScreen(char **screen);
// 辅助函数5 计算相邻细胞中活细胞的数目
int getNearbyCellsCount(char **screen, int x, int y);
// 辅助函数6 更新细胞的状态
void update(char **screen);
// 辅助函数7 判断细胞状态是否没有变化
bool isStateSame(char **screen, char **newScreen);
// 辅助函数8 复制 screen1 到 screen2
void screenCopy(char **screen1, char **screen2);


int main()
{
    printf("***************\n"
           "** Cellular! **\n"
           "***************\n"
           "\nPress any key to start...\n");
    char opera;
    opera = getchar();
    srand(time(nullptr));
    char **screen1 = init(randD());
    char **screen2 = init(0);
    system("cls");
    printScreen(screen1);
    while (true) {
        printf("\nPress any key to continue...\n"
               "Press q to quit game\n");
        opera = getchar();
        if (opera == 'q') {
            break;
        }
        screenCopy(screen1, screen2);
        update(screen1);
        if (isStateSame(screen1, screen2)) {
            printf("It is the final status.\n");
            break;
        }
        system("cls");
        printScreen(screen1);
    }
    deleteScreen(screen1);
    deleteScreen(screen2);
    return 0;
}

// 辅助函数1 返回一个[0, 1]的随机浮点数
double randD()
{
    return 1.0*rand()/RAND_MAX;
}

// 辅助函数2 初始化生命空间
char **init(double lifr_prob) 
{
    /*
    初始化游戏，以life_prob的概率生成活细胞
    输入：life_prob——生成活细胞的概率
    输出：width x height大小的细胞状态
    */
    char **screen = new char*[hight + 2];
    for (int i = 0; i < hight + 2; ++i) {
        screen[i] = new char[width + 2];
    }
    for (int i = 0; i < hight + 2; ++i) {
        for (int j = 0; j < width + 2; ++j) {
                screen[i][j] = ' ';
        }
    }
    for (int i = 1; i <= hight; ++i) {
        for (int j = 1; j <= width; ++j) {
            if (randD() < lifr_prob) {
                screen[i][j] = 'o';
            }
        }
    }
    return screen;
}

// 辅助函数3 释放生命空间内存
void deleteScreen(char **screen)
{
    for (int i = 0; i < hight + 2; ++i) {
        delete[] screen[i];
        screen[i] = nullptr;
    }
    delete[] screen;
    screen = nullptr;
}

// 辅助函数4 打印细胞状态
void printScreen(char **screen)
{
    /*
    screen 参数类型与init()函数返回值类型一致，表示当前
    细胞状态。由于屏幕打印时行距比字符宽度大很多，所以请在打印
    每个字符后面加空格，并在最后一个字符的后面打印'|'表示生命
    空间的边界(注意：表示生命空间边界的符号可以换成你们喜欢的符号，不局限
    于'|')
    */
    putchar(' ');
    for (int i = 0; i <= hight*2; ++i) {
        putchar('_');
    }
    putchar('\n');
    putchar('|');
    for (int i = 0; i <= hight*2; ++i) {
        putchar(' ');
    }
    putchar('|');
    putchar('\n');
    for (int i = 1; i <= hight; ++i) {
        putchar('|');
        putchar(' ');
        for (int j = 1; j <= width; ++j) {
            putchar(screen[i][j]);
            putchar(' ');
        }
        putchar('|');
        putchar('\n');
    }
    putchar('|');
    for (int i = 0; i <= hight*2; ++i) {
        putchar('_');
    }
    putchar('|');
    putchar('\n');
}

// 辅助函数5 计算相邻细胞中活细胞的数目
int getNearbyCellsCount(char **screen, int x, int y)
{
    /*
    get_near_by_cells_count()的形参有：screen, i,j；
    其中screen与init()函数的返回值类型一致，表示当前细胞的状态；
    i和j均为int类型，表示生命空间各细胞,也即：n*n空间内的格子，所在的行号和列号
    函数返回值为int类型，表示位置(i，j)的细胞其相邻活细胞的数量
    */
   int cnt = 0;
   for (int i = x-1; i <= x+1; ++i) {
       for (int j = y-1; j <= y+1; ++j) {
           if (screen[i][j] == 'o') {
               ++cnt;
           }
       }
   }
   if (screen[x][y] == 'o') {
       --cnt;
   }
   return cnt;
}

// 辅助函数6 更新细胞的状态
void update(char **screen)
{
    /*
    该函数包含一个参数，screen，其类型与init()函数返回值类型一致，表示当前
    细胞状态。该函数根据传入生命空间screen内细胞的状态，利用更新原则对细胞
    状态进行更新，并返回更新后的细胞状态，返回值类型与screen类型一致
    TIPS: 不返回值
    */
    int count[hight+1][width+1];
    for (int i = 1; i <= hight; ++i) {
        for (int j = 1; j <= width; ++j) {
            count[i][j] = getNearbyCellsCount(screen, i, j);
        }
    }
    for (int i = 1; i <= hight; ++i) {
        for (int j = 1; j <= width; ++j) {
            if (count[i][j] == 3) {
                screen[i][j] = 'o';
            } else if (count[i][j] != 2) {
                screen[i][j] = ' ';
            }
        }
    }
}

// 辅助函数7，判断细胞状态是否没有变化
bool isStateSame(char **screen, char **newScreen)
{
    /*
    参数screen和new_screen分别表示更新前和更新后的细胞状态
    根据判断更新前后细胞的状态，如果更新前细胞(i,j)的状态与更新后细胞(i,j)
    的状态一致，则返回True；否则返回False
    */
   for (int i = 1; i <= hight; ++i) {
       for (int j = 1; j <= width; ++j) {
           if (screen[i][j] != newScreen[i][j]) {
               return false;
           }
       }
   }
   return true;
}

// 辅助函数8 复制 screen1 到 screen2
void screenCopy(char **screen1, char **screen2)
{
    for (int i = 1; i <= hight; ++i) {
        for (int j = 1; j <= width; ++j) {
            screen2[i][j] = screen1[i][j];
        }
    }
}

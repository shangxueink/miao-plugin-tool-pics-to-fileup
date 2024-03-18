#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <conio.h> // 引入conio.h以使用_getch()，用于等待用户按键 

void createDirAndMoveFile(const char *fileName) {
    char folderName[256] = {0};
    strncpy(folderName, fileName, strrchr(fileName, '.') - fileName);
    mkdir(folderName); // 在Windows下调整为单参数
    char newFilePath[512] = {0};
    // Windows平台路径分隔符的处理
    snprintf(newFilePath, sizeof(newFilePath), "%s/%s", folderName, "main.png");
    rename(fileName, newFilePath);
    printf("已打包%s进入%s文件夹为main.png\n", fileName, folderName);
}

int isImageFile(const char *fileName) {
    const char *dot = strrchr(fileName, '.');
    if (!dot || dot == fileName) return 0;
    if (strcmp(dot, ".png") == 0 || strcmp(dot, ".jpg") == 0 || strcmp(dot, ".jpeg") == 0 || strcmp(dot, ".gif") == 0) return 1;
    return 0;
}

void processImages() {
    DIR *d;
    struct dirent *dir;
    int foundFiles = 0; // 跟踪是否找到文件
    d = opendir(".");
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (isImageFile(dir->d_name)) {
                createDirAndMoveFile(dir->d_name);
                foundFiles++;
            }
        }
        closedir(d);
    }
    if (!foundFiles) {
        printf("当前目录下没有找到图片文件......\n");
        _getch(); 
    }
}

int main() {
    char confirm;
    printf("本脚本旨在将当前文件夹下的图片打包进子文件夹，并且重命名为main.png\n");
    printf("你要确定要继续执行吗？（Y/N）: ");
    scanf(" %c", &confirm);

    if (confirm == 'N' || confirm == 'n') {
        printf("取消操作...按下任意键退出......\n");
        _getch(); 
        return 0;
    } else if (confirm != 'Y' && confirm != 'y') {
        printf("无效的输入...程序退出。\n");
        _getch(); 
        return 0;
    }

    processImages();
    printf("处理已完成！按下任意键退出！\n");
    _getch(); 
    return 0;
}

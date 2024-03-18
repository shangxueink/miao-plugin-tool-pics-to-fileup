#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <conio.h> // ����conio.h��ʹ��_getch()�����ڵȴ��û����� 

void createDirAndMoveFile(const char *fileName) {
    char folderName[256] = {0};
    strncpy(folderName, fileName, strrchr(fileName, '.') - fileName);
    mkdir(folderName); // ��Windows�µ���Ϊ������
    char newFilePath[512] = {0};
    // Windowsƽ̨·���ָ����Ĵ���
    snprintf(newFilePath, sizeof(newFilePath), "%s/%s", folderName, "main.png");
    rename(fileName, newFilePath);
    printf("�Ѵ��%s����%s�ļ���Ϊmain.png\n", fileName, folderName);
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
    int foundFiles = 0; // �����Ƿ��ҵ��ļ�
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
        printf("��ǰĿ¼��û���ҵ�ͼƬ�ļ�......\n");
        _getch(); 
    }
}

int main() {
    char confirm;
    printf("���ű�ּ�ڽ���ǰ�ļ����µ�ͼƬ��������ļ��У�����������Ϊmain.png\n");
    printf("��Ҫȷ��Ҫ����ִ���𣿣�Y/N��: ");
    scanf(" %c", &confirm);

    if (confirm == 'N' || confirm == 'n') {
        printf("ȡ������...����������˳�......\n");
        _getch(); 
        return 0;
    } else if (confirm != 'Y' && confirm != 'y') {
        printf("��Ч������...�����˳���\n");
        _getch(); 
        return 0;
    }

    processImages();
    printf("��������ɣ�����������˳���\n");
    _getch(); 
    return 0;
}

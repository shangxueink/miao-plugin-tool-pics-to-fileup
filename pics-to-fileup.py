import os
import shutil
import sys

def move_images_to_folders():
    try:
        # 获取当前目录下所有文件的列表
        files = os.listdir('.')
        images = [file for file in files if file.lower().endswith(('.png', '.jpg', '.jpeg', '.bmp', '.gif', '.tiff'))]

        # 如果没有图片，提示用户并退出
        if not images:
            print("当前目录下没有图片。")
            return

        # 遍历图片文件列表
        for image in images:
            # 创建与图片文件名同名的文件夹，如果文件夹不存在的话
            folder_name = os.path.splitext(image)[0]
            if not os.path.exists(folder_name):
                os.makedirs(folder_name)
            
            # 移动图片到对应的文件夹，并重命名为main.png
            src_path = os.path.join(os.getcwd(), image)
            dest_path = os.path.join(os.getcwd(), folder_name, 'main.png')
            shutil.move(src_path, dest_path)
            print(f"Moved {image} to {folder_name}")

    except PermissionError:
        print("没有足够的权限来执行这个操作。请检查您的权限或以管理员身份运行脚本。")
    except Exception as e:
        print(f"发生错误: {e}")

def main():
    print("本脚本旨在将当前文件夹下的图片打包进子文件夹，并且重命名为main.png")
    confirmation = input("你要确定要继续执行吗？（Y/N）: ").upper()
    if confirmation == 'Y':
        move_images_to_folders()
    else:
        print("执行已取消。")

if __name__ == "__main__":
    try:
        main()
    except SystemExit:
        pass
    finally:
        input("\n按下任意键退出...")
        sys.exit()
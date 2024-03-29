
# 图片整理脚本
这个脚本可以自动整理当前目录下的图片文件。它将图片移动到以图片文件名命名的子文件夹中，并将每张图片重命名为`main.png`。

适用于快速生成符合要求的Miao-plugin的背景图存放格式
## 功能
- 自动识别当前目录下的图片文件（支持png, jpg, jpeg, bmp, gif, tiff格式）。
- 为每张图片创建一个与其文件名相同的子文件夹（如果尚不存在）。
- 将图片移动到对应的子文件夹，并重命名为`main.png`。
- 处理无图片文件、无访问权限等异常情况。
## 如何使用
1. 将脚本保存到您想要整理图片的目录。这个目录应该是存放一堆以 符合文件夹命名要求 命名的大量图片
2. 双击运行`pics-to-fileup.exe`
3. 按照提示操作。
4. 生成一堆子文件夹，每个文件夹里都有`main.png`。
5. 手动将生成的文件夹，移动到 `Yunzai根目录\plugins\miao-plugin\resources\help\theme` 目录下。生成的文件夹应该与默认存在的`default`文件处于同级
## 注意事项
- 在执行脚本之前，请确保您对当前目录下的文件有足够的读写权限。
- 执行脚本可能会覆盖同名的`main.png`文件，建议事先备份重要数据。
- 如果遇到权限错误，请尝试以管理员身份运行脚本。
## 常见问题与解决方案
**问题：脚本提示“当前目录下没有图片。”但我确定有图片怎么办？**
解决方案：请检查图片文件的扩展名是否为脚本支持的格式（png, jpg, jpeg, bmp, gif, tiff），并确保它们不是隐藏文件或受保护的系统文件。
**问题：脚本执行时提示“没有足够的权限来执行这个操作。”**
解决方案：请尝试以管理员身份运行脚本或检查当前用户对图片文件及目标文件夹的访问权限。
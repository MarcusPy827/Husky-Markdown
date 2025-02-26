# 这是什么
我尝试使用`Vue.js`代替`QWidget`作为程序的前端，但无法在Qt程序运行时热更新Vue代码；我还需要将我写的各种组件打包进一个单独的HTML文件中并且替换资源相对路径为qrc路径，故而我无法在浏览器中调试整个前端界面。

为了方便调试，这个文件夹里的Vue项目是此阅读器的“原版” UI，我会先更新这里的页面，测试它们有没有问题，如果没有问题再将改动应用至`res/webview`。

# What does this folder do?
I tried to use `Vue.js` instead of `QWidget` for this program for the user interface. However, I could not hot reload Vue code while the program is running; I also need to put all the vue components into individual HTML pages and replace all the paths to assets with qt resource paths, making me unable to debug the user interface in browsers.

To make debugging easy, the "original" user interface source is stored in this folder. I will first apply changes to Vue pages here to test if there are new problems with these changes, and once they are ready, I will apply these changes to `res/webview`.
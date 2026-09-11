# ***Git***

### 初始化：
设置Git用户名：
`git config --global user.name "用户名"`
设置Git邮箱：
`git config --global user.email "邮箱"`

### 初次使用：
#### 第一步：
###### 新建：初始化git仓库，在该文件夹生成隐藏的 .git 文件夹
`git init`
###### 克隆：将别人的Github仓库克隆到本地
`git clone https://github.com/用户名/仓库名.git`
#### 第二步：将文件加入暂存区
###### 所有文件：
`git add .`
###### 加单个文件：
`git add main.cpp`
###### 加多个指定文件：(多个文件使用空格隔开，文件名带空格的话用引号包裹“My file.txt”)
`git add main.cpp test.cpp README.md`
###### 文件格式匹配：
*cpp:
`git add *.cpp`
*h:
`git add src/*.h`

#### 第三步：提交到本地仓库
`git commit -m "提交的备注"`

#### 第四步：关联远程Github仓库（只需执行一次）
`git remote add origin https://github.com/用户名/仓库名.git`

##### （获取链接：进入仓库后，展开Code可以获得仓库的链接）
![Github截图](https://bee-reg-ab.imagency.cn/mr/6001/26/40a994dddd706077f63790bf0b2543f0.png "“展开绿色的Code可以获取仓库链接”")
`git remote add origin https://github.com/Seedofking/C.git`

###### 查看远程仓库是否绑定成功：
`git remote -v`

#### 第五步：推送到Github远程仓库
`git push -u origin main`

###### 如果报错 Does not match any, 就换成`git push -u origin master`，因为Git旧版本分支默认叫 master
###### 使用`git config --global init.defaultBranch main`可以把本地默认分支改成main
###### 使用`git branch`可以查看本地所有分支

### 后续使用：
#### 第一步：文件加入缓存区
`git add .`/`git add mian.cpp`/`git add main.cpp test.cpp README.md`/`git add *.cpp`/`git add src/*.h`

#### 第二步：提交到本地仓库
`git commit -m "更新xxx/新增xxx"`

#### 第三步：提交代码
`git push`

##### 如果出现 The upstream branch of your current branch does not much:(本地分支名与上游分支名不匹配)
###### 临时方案：把本地当前 HEAD（也就是本地 master 分支）推送到远程仓库的main分支
`git push origin HEAD:main`,但是执行该命令不会绑定上游分支，下次push还是要写完整命令
###### 绑定上游方案：
`git push -u origin HEAD:main`,使用-u绑定上游后下次就可以直接git push
##### 修改本地分支名方案：
###### 第一步：将本地master分支名重命名为main
`git branch -m master main`
###### 第二步：将本地main分支绑定远程origin main并推送
`git push -u origin main`

#### 通用字符解释：
#### -u
##### 绑定上游分支：
`-u`等价于`--set-upstream`,用于git push
upstream = 远程仓库上对应的那条分支
`git push -u origin master:main`执行完之后就会把下游分支branch绑定上游分支main，下次就不用再写完整命令
本地与github同名就写`git push -u origin main`
以后可以直接写`git push`推送，`git pull`拉取
#### -m
##### 1.提交信息：
`-m`等价于`--message`
`-m "备注"`可以直接在命令行写本次提交的说明文字，跳过vim编辑器
`git commit -m "备注"`
##### 2.移动/重命名分支：
此时`-m`等价于`--move`,作用是重命名分支
`git branch -m master main`将旧分支名字master重命名为新分支名字main

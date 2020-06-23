##实现一个请求
- 注册一个路由
    - urls中
     - url
        - 参数1 匹配规则  正则
        - 视图函数
            - 对应的是views中的一个函数
                - 没有括号
 - 去views实现对应的视图函数
    - 第一个参数是request
    - 永远记得返回Response
 
##html
- ul>li
- ul*5   
- ul>li*5    

##模版配置
- 两种
    - 在App中进行模版配置
        - 只需在App根目录中创建templates文件夹即可
        - 如果想让代码自动提示，应该标志文件夹为模版文件夹
    - 在项目目录中进行模版配置
        - 需要在项目目录中创建模版文件夹并标记
        - 需要在setting中进行注册
    - 在开发中使用第二种
        - 模版可以继承，复用
     
##路由优化配置
- 项目如果逻辑过于复杂，可以进行拆分
- 拆为多个应用
- 继续拆分路由器urls
    - 在App中创建自己的urls
        - urlpatterns 路由规则列表
        - 在根urls中进行路由的包含
    - 子路由使用
        - 根路由规则 + 子路由规则
##models 使用了ORM技术
- Object Relational Mapping 对象关系映射
- 将业务逻辑进行了一个解耦合
    - object.save()
    - object.delete()
- 关系型数据库
    - DDL
    - 通过models定义实现  数据库表的定义
- 数据操作
    - 增删改查
    - 存储
        - save()
    - 查询
        - 查所有 object.all()
        - 查单个 object.get(pk = xx)
    - 更新
        - 基于查询的
        - 查好的对象，修改属性，然后save()
    - 删除
        - 基于查询的
        - 调用delete()
     
##连接mysql驱动
- mysqlclient
    - p2p3都能直接使用
    - 致命缺点
        - 对mysql安装有要求，必须指定位置存在配置文件
- python-mysql
    - 对PY2支持很好
    - PY3不支持
- pymysql
    - 23都支持
    - 它还可以伪装成前面的库
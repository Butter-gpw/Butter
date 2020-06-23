##MIME
- 作用：指定传输数据使用哪种形式打开
- 格式：大类型/小类型
    - image/png
    - image/jpg

##Json
- JsonObject
    - {}
    - key-value
- JsonArray
    - []
    - 列表中可以是普通数据类型，也可以是JsonObject
- JsonObject和JsonArray可以嵌套
- 给移动端的json
- 给Ajax
    - 前后端分离
    - DRF
- Google Chrome
    - JsonFomatter
    - JsonView
       
##HttpResponse
- HttpResponseRedirect
    - 重定向
    - 302
    - 简写redirect
- JsonResponse
    - 以Json格式返回数据
    - 重写__init__，序列化Json，指定content——type为application/json 
- HttpResponsePermanentRedirect
    - 重定向，永久性
    - 301
- HttpResponseBadRequest
    - 400
- HttpResponseNotFound
    - 404
- HttpResponseForbidden
    - 403
- HttpResponseNotAllowed
    - 405
- HttpResponseServerError
    - 500
- Http404
    - Exception
    - raise 
    
    
##会话技术
- 出现场景
    - 服务器如何识别客户端
    - Http在Web开发中基本都是短连接
- 请求生命周期
    - 从Request开始
    - 到Response结束
- 种类
    - Cookie
        - 客户端会话技术
            - 数据存储在客户端
        - 键值对存储
        - 支持过期时间
        - 默认Cookie会自动携带，本网站所有Cookie
        - Cookie不能跨域名，跨网站
        - 通过HttpResponse
        - Cookie默认不支持中文
        - 可以加盐
            - 加密
            - 获取的时候需要解密
    - Session
        - 服务端会话技术
        - 数据存储在服务器中
        - 默认Session存储在内存中
        - Django中默认会把Session持久化到数据库中
        - Django中Session默认过期时间是14天
        - 主键是字符串
        - 数据是使用了数据安全
            - 使用的是base64
            - 在前部添加了一个混淆串
         - Session依赖于Cookie
    - Token
        - 服务端会话技术
        - 自定义的session
        - 如果web页面开发中，使用起来和Session基本一致
        - 如果使用在移动端或客户端开发中通常以Json形式传输，需要移动端自己存储Token，需要获取Token冠梁数据的时候，主动传递Token
    
    - Cookie和Session，Token对比
        - Cookie使用起来更简洁，服务器压力更小，数据不是很安全
        - Session服务器要维护Session， 相对安全
        - Token拥有session的所有优点，自己维护略微麻烦，支持更多的终端
        
##CSRF
- 防跨站攻击
- 防止恶意注册，确保客户端是我们自己的客户端
- 使用了cookie中的csrftoken 进行验证，传输
- 服务器发送给客户端，客户端将cookie获取过来，还要进行 编码转换（数据安全）
- 如何实现的
    -在我们存在csrf_token 标签的页面中， 响应会自动设置一个cookie，csrftoken
    - 当我们提交的时候，会自动验证csrf_token
    - 验证通过，正常执行以后流程，验证不通过，直接403


##目前状态
- MTV
    - 基本完成
    - Template不会再讲
    - Views也不会再讲
    - Model
        - Model关系
        - Model继承
    - 高级
        - 第三方插件
        - 底层的部分原理
         - AOP 面向切面变成
            - 反扒
            - 安全
         - 文件上传
         - 前后端分离
            - RESTful
         - 日志
         - 后台管理
         - 用户角色，用户权限
         - 部署
         - 支付宝支付
##算法
- 编码解码
    - base64
    - urlencode
- 摘要算法，指纹算法，杂凑算法
    - MD5,SHA
        - MD5默认是128的二进制
        - 32位十六进制
        - 32位的Unicode
    - 单向不可逆的
    - 不管输入多长，输出都是固定长度
    - 只要输入有任意变更，输出都会发生巨大的变化
##加密
- 对称加密
    - 一把钥匙
    - DES,AES
    - 加密加密效率高
    - 钥匙一旦丢失，所有数据就全玩完
- 非对称加密
     - 两把钥匙，成对的
     - 公钥和私钥
     - RSA,PGP
     - 安全性最高
     - 算法复杂，需要时间长
     - 支付宝，微信都是使用RSA
     - 
##编码
- ASCII（256）
- Unicode()

##优秀程序
- 松耦合
   - 解耦合
- 高内聚    

##登陆
- 首先有一个页面
    - 页面中有输入框
    - 有登陆按钮
- 点完登陆，默认进入个人中心
- 个人中心可以显示用户名

##爬虫
- 模拟人去请求数据
- 提取数据
- 存储数据
    
    
##核心内容
- 数据爬取
- 数据提取
- 数据存储
- 提升效率
    - 进程
    - 线程
    - 协程
       
##实现Cookie储存中文
- Base64
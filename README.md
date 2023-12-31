1. **策略模式**
   将if-else方法, 改为(key, value)方法, 实际上也可以通过map实现, 目的还是在于使流程更加清晰
   比如在多层地图匹配时, 会有根据不同地图配置不同参数的情况, 所以需要将其保存在map中, 根据需要调用不同地图
2. **责任链模式**
   一般责任链模式会实现链式结构, 便于观测出问题位置, 一般类中会出现两种函数{ set_next(Handle* next); hang_request();}
3. **模板方法模式**
   设置一个base父类, 只是在个别流程上会有差异, 这部分差异部分可以在子类中实现
   比如, 我想实现不同环境下的slam模式(bad_scan, pure_odom, tilted...), 我拥有一个normal_slam类, 但实现上会有一些小小的差异,
   就需要通过子类来根据需要自定义实现
4. 观察者方法
   观察者模式的目的, 实际上可以通过一个模板文件通用观察所有相关类状态, 这个模式的好处是可开关观测相关类状态,
   一般存在抽象观察类, 具体观察类, 抽象目标类, 具体目标类
5. **工厂模式**
   工厂模式的目的实际上是生产者与指挥者相剥离, 在使用时只需要构造虚类工厂, 根据不同需要设计所需要的产品,
   比如我想实现路径规划, 但我想通过(A*, D*)等进行全局规划路径, 这时候只按需构造所需类即可, 实际上, 此方法是对简单工厂模式的补充
   一般分成三部分: 1, 产品虚类 2,产品实类 3, 工厂类(1, 简单工厂根据type输出产品实类, 2, 工厂模式通过设计工厂虚类实现实际调用
6. 适配器模式
   功能相同接口不同, 一般根据不同场景变换
7. **单例模式**
   一般用于全局使用, 并且只可构造一次
8. **门面模式**
   只单一接口, 一般是一个接口类, 面向外部
9. 修饰器模式
   一般用于拓展新功能
10. 代理模式
    一般分为三个类: 1, 需要代理的接口虚类; 2, 实现接口类; 3, 代理类(实现通过接口类实类实现)
11. 桥接模式
    用于多对多类, 不必要设计太多类, 例如手机品牌是一个分类, 手机类型是一个分类(老年机, 智能机, 专业机等)


这里比较有趣且常用的模式:

单例模式, 门面模式, 模板方法, 责任链模式, 策略模式

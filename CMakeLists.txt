cmake_minimum_required(VERSION 3.26)
project(AlgorithmProj)

set(CMAKE_CXX_STANDARD 17)

add_executable(AlgorithmProj
#        LuoGu/Part10/Array-Enum/P2241.cpp
#        LuoGu/Part10/Array-Enum/P2089.cpp
#        LuoGu/Part10/Array-Enum/P1618.cpp
#        LuoGu/Part10/Subset-Enum/P1036.cpp
#        LuoGu/Part10/Subset-Enum/P1157.cpp
#        LuoGu/Part10/Circle-Enum/P1618.cpp
#        LuoGu/Part11_Recursion/P1255.cpp
#        LuoGu/Part11_Recursion/P1002.cpp
#        LuoGu/Important_Method/next_permutation_method.cpp
#        LuoGu/Part10/Array-Enum/P1706.cpp
#        LuoGu/Part10/Array-Enum/Poj1256.cpp
#        LuoGu/Part11_Recursion/P1044.cpp
#        LuoGu/competition/test.cpp
#        LuoGu/competition/XinXiSuYanDaSai/JuanYi/JianShiTou.cpp
#        LuoGu/competition/XinXiSuYanDaSai/JuanYi/PanDuanShuZiChuXianJiCi.cpp
#        LuoGu/competition/XinXiSuYanDaSai/JuanYi/HuaXueBanDaBao.cpp
#        LuoGu/competition/XinXiSuYanDaSai/JuanYi/TonJiKaoShiChenJi.cpp
#        LuoGu/competition/XinXiSuYanDaSai/JuanYi/ShanChuKWeiShuZi.cpp
#        LuoGu/competition/XinXiSuYanDaSai/JuanYi/PeiBeiShu.cpp
#        LuoGu/competition/XinXiSuYanDaSai/QiTaZhenTi/ZhanShenBaiYi.cpp
#        LuoGu/competition/XinXiSuYanDaSai/QiTaZhenTi/JiSuanGeZiDiBan.cpp
#        LuoGu/competition/XinXiSuYanDaSai/QiTaZhenTi/HouZiZhaiTao.cpp
#        LuoGu/competition/XinXiSuYanDaSai/QiTaZhenTi/ZhengShuHuanChengDaiFenShu.cpp
#        LuoGu/competition/XinXiSuYanDaSai/QiTaZhenTi/BookArrangement.cpp
#        LuoGu/competition/XinXiSuYanDaSai/QiTaZhenTi/TimeConverter.cpp
#        LuoGu/competition/XinXiSuYanDaSai/QiTaZhenTi/ChemicalReaction.cpp
#        LuoGu/competition/XinXiSuYanDaSai/QiTaZhenTi/LeapYear.cpp
#        LuoGu/competition/XinXiSuYanDaSai/QiTaZhenTi/SensorData.cpp
#        LuoGu/competition/XinXiSuYanDaSai/QiTaZhenTi/KeyboardInput.cpp
#        LuoGu/competition/XinXiSuYanDaSai/QiTaZhenTi/erwtgrg.cpp
#        LuoGu/competition/XinXiSuYanDaSai/QiTaZhenTi/xasgtryrtfuyh.cpp
        0725/P1424.cpp
        #                main.cpp
#        "LuoGu/Part8/8_1_SimulationAlgorithm/P1042.cpp"
#        "LuoGu/Part8/8_1_SimulationAlgorithm/P2670.cpp"
#        LuoGu/Part6/6_1_CharArray/P6565.cpp
        #        LuoGu/P2670.cpp
#        LuoGu/Part8/8_2_HighPrecisionAlgorithm/P1601.cpp
#        LuoGu/Part8/8_2_HighPrecisionAlgorithm/P2142.cpp
#        LuoGu/Part8/8_2_HighPrecisionAlgorithm/P2142_pls.cpp
#        "LuoGu/Part8/8_1_SimulationAlgorithm/P3613.cpp"
#        LuoGu/P1093.cpp
#        LuoGu/P2676.cpp
#        LuoGu/P1152.cpp
#        LuoGu/P1068.cpp
#        LuoGu/P5143.cpp
#        LuoGu/P1104.cpp
#        LuoGu/Part9/P1012.cpp
        #        LuoGu/P1303.cpp
#        LuoGu/P1009.cpp
#        LuoGu/P4924.cpp
#        LuoGu/P1328.cpp
#        LuoGu/P1518.cpp
#        LuoGu/P1067.cpp
#        LuoGu/P1067_plus.cpp
#        LuoGu/P1098.cpp
        #        Acwing/1.语法基础课/第8课_STL.cpp
#        "Acwing/1.语法基础课/1.6 习题 及 1.7 类、结构体、指针与引用/第一题/810(函数)_绝对值.cpp"
#        "Acwing/1.语法基础课/1.6 习题 及 1.7 类、结构体、指针与引用/第二题/806(函数)_两个数的和.cpp"
#        "Acwing/1.语法基础课/1.6 习题 及 1.7 类、结构体、指针与引用/第三题/807(函数)_区间求和.cpp"
#        "Acwing/1.语法基础课/1.6 习题 及 1.7 类、结构体、指针与引用/第四题/809(函数)_最小公倍数.cpp"
#        "Acwing/1.语法基础课/1.6 习题 及 1.7 类、结构体、指针与引用/第五题/814(函数)_复制数组.cpp"
#        "Acwing/1.语法基础课/1.6 习题 及 1.7 类、结构体、指针与引用/第七题/816(函数)_数组翻转.cpp"
#        "Acwing/1.语法基础课/1.6 习题 及 1.7 类、结构体、指针与引用/第八题/817(函数)_数组去重.cpp"
#        "Acwing/1.语法基础课/1.6 习题 及 1.7 类、结构体、指针与引用/第九题/818(函数)_数组排序.cpp"
#        "Acwing/1.语法基础课/1.6 习题 及 1.7 类、结构体、指针与引用/第十题/821(函数)_跳台阶.cpp"
#        Acwing/2.算法基础课/第二章数据结构/Trie树/第一题/835_Trie字符串的统计.cpp
)

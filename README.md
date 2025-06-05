---

# Campus Navigation System

## 项目概述
欢迎使用 **Campus Navigation System**，这是一个专为广东外语外贸大学（广外）师生设计的校园导航系统。系统利用图论算法（如 Floyd 算法）提供最短路径规划、实时导航和校园环游功能，并支持地图查询、步数记录和排行榜展示。通过简洁的用户界面和多彩的视觉风格，旨在提升校园探索的便捷性和趣味性。

## 功能特点
- **地图查询**：查看校园的邻接矩阵和邻接表。
- **最短路径规划**：输入起点和终点，获取最短路径。
- **环游校园**：从任意起点探索所有地点。
- **实时导航**：动态显示路径和可选地点。
- **排行榜**：记录步数，与他人比拼最优路线。
- **用户友好**：简洁界面，搭配颜色设置，提升体验。

## 系统要求
- **操作系统**：Windows（由于使用了 Windows 特定的颜色设置函数 `SetConsoleTextAttribute`）。
- **编译器**：支持 C++ 的编译器（如 g++ 或 MSVC）。
- **依赖**：无外部库，标准 C++ 库即可。

## 安装与编译
1. **克隆仓库**：
   ```bash
   git clone https://github.com/yourusername/CampusNavigationSystem.git
   cd CampusNavigationSystem
   ```

2. **确保数据文件**：
   - 将 `input.txt`（包含地点和边数据）和 `rank.txt`（排行榜数据）放入 `data/` 目录。
   - 示例 `input.txt` 格式：
     ```
     31  # 地点数量
     东北门 学校正门
     东南门 校园侧门
     ...  # 其他地点和简介
     50   # 边数量
     东北门 艺术楼 108
     艺术楼 学术报告厅 75
     ...  # 其他边信息（起点 终点 权重）
     ```

3. **编译项目**：
   - 使用 Visual Studio 2022编译

4. **运行程序**：
   - 使用 Visual Studio 2022运行程序
   - 运行“GDUFS Navigation System.exe”

## 使用方法
1. **启动程序**：
   - 运行程序后，进入欢迎界面，选择“1. 开始”加载地图。

2. **功能菜单**：
   - **地图查询**：选择“1”，可查看邻接矩阵、邻接表，或查询最短路径。
   - **校园导航**：选择“2”，输入起点和终点开始导航，实时显示路径和步数。

3. **交互操作**：
   - 输入地点名称（无空格，例如“东北门”），系统会显示可前往地点。
   - 输入“退出”结束导航。
   - 按 Enter 键返回菜单。

4. **输出文件**：
   - 程序会生成 `output/adj_matrix.txt` 和 `output/adj_list.txt`，记录图结构。

## 文件结构
```
CampusNavigationSystem/
├── include/                    # 头文件目录
│   ├── campus_map.h           # 定义校园地图相关结构体和函数声明
│   ├── mystack.h              # 实现模板栈类，用于路径回溯
│   ├── navigation.h           # 声明导航相关函数和数据结构
│   ├── path_finding.h         # 声明路径规划相关函数
│   ├── style.h                # 定义颜色宏和设置函数
│   └── user_interface.h       # 声明用户界面相关函数
├── src/                       # 源文件目录
│   ├── campus_map.cpp         # 实现地图加载和图结构创建
│   ├── main.cpp               # 程序入口，启动用户界面
│   ├── navigation.cpp         # 实现导航和排行榜功能
│   ├── path_finding.cpp       # 实现路径规划算法
│   ├── style.cpp              # 实现颜色设置功能
│   └── user_interface.cpp     # 实现用户界面交互
├── data/                      # 输入数据文件
│   ├── input.txt              # 存储地点和边数据
│   └── rank.txt               # 存储排行榜数据
└── output/                    # 输出文件（可选）
    ├── adj_matrix.txt         # 存储邻接矩阵
    └── adj_list.txt           # 存储邻接表
```

## 开发信息
- **开发人员**：
  - 负责人：林子豪（统筹协调项目推进）
  - 组员：张涛、曾琪（算法实现，功能设计）
- **开发时间**：截至 2025 年 5 月 31 日
- **语言**：C++

## 贡献指南
1. **提出问题**：通过 Issues 报告 bug 或建议新功能。
2. **提交代码**：Fork 仓库，创建新分支，提交 Pull Request。
3. **代码规范**：遵循 Doxygen 注释风格，确保可读性。


## 联系方式
如有疑问，请通过 [780551528@qq.com] 联系我们。

---

### 备注
- **时间更新**：2025 年 5 月 31 日 ”。
- **GitHub 链接**：https://github.com/Passerby-A-study/GDUFS-Navigation-System
- **许可证**：默认使用 MIT License，可根据需要调整。

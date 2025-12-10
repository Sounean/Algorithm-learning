# Cursor 优化指南：让 AI 更好地理解你的项目固定模式

## 一、核心策略

### 1. 创建代码模板库（Code Templates）

在项目根目录创建 `.cursor/templates/` 文件夹，存放各种固定模式的代码模板：

```
项目根目录/
├── .cursor/
│   ├── templates/
│   │   ├── navigation_template.md      # 界面跳转模板
│   │   ├── network_request_template.md # 网络请求模板
│   │   ├── component_template.md       # 组件模板
│   │   └── ...
│   └── rules.md                        # 项目规则说明
```

### 2. 创建项目规则文档（.cursorrules）

在项目根目录创建 `.cursorrules` 文件，让 Cursor 自动读取项目规范：

```markdown
# 项目代码规范

## 界面跳转规范
- 使用统一的 NavigationService 进行页面跳转
- 跳转前必须进行参数验证
- 跳转后需要记录日志
- 示例：[参考 templates/navigation_template.md]

## 网络请求规范
- 使用统一的 ApiClient 封装
- 所有请求必须包含错误处理
- 使用统一的响应格式
- 示例：[参考 templates/network_request_template.md]

## 代码风格
- 使用 4 空格缩进
- 函数命名使用驼峰命名法
- 类名使用大驼峰命名法
```

### 3. 使用示例代码文件

创建 `examples/` 目录，存放各种固定模式的完整示例：

```
examples/
├── navigation_example.cpp
├── network_request_example.cpp
└── component_example.cpp
```

## 二、具体实施步骤

### 步骤 1：识别固定模式

列出你项目中常见的固定代码模式：
- [ ] 界面跳转
- [ ] 网络请求
- [ ] 数据验证
- [ ] 错误处理
- [ ] 日志记录
- [ ] 其他：_______

### 步骤 2：提取模板代码

从现有代码中提取标准模式，创建模板文件。

### 步骤 3：编写详细注释

在模板中添加详细的中文注释，说明：
- 为什么这样写
- 哪些地方可以修改
- 哪些地方必须保持不变

### 步骤 4：创建上下文文件

在 `.cursor/context/` 目录下创建上下文文件，帮助 AI 理解项目结构。

## 三、使用技巧

### 1. 在对话中引用模板

当需要生成代码时，可以这样提示 Cursor：

```
请参考 .cursor/templates/navigation_template.md 中的模式，
帮我生成从 LoginPage 跳转到 HomePage 的代码
```

### 2. 使用 @ 符号引用文件

在 Cursor 的聊天中，使用 `@文件名` 来引用特定文件：
- `@navigation_template.md` - 引用跳转模板
- `@network_request_template.md` - 引用网络请求模板

### 3. 创建代码片段（Snippets）

在 Cursor 中配置代码片段，快速插入固定模式。

### 4. 使用 Agent 模式

在 Cursor 中使用 Agent 模式时，明确告诉 AI：
```
请按照项目规范生成代码，参考 examples/ 目录下的示例
```

## 四、BMAD Code 方法论应用

### 1. 多角色协作模拟

- **产品经理角色**：定义需求规范
- **架构师角色**：定义代码结构
- **开发者角色**：生成具体代码

### 2. 创建角色提示词

在 `.cursor/agents/` 目录下创建不同角色的提示词文件。

## 五、持续优化

1. **收集反馈**：记录 AI 生成的代码与期望的差异
2. **更新模板**：根据实际使用情况不断优化模板
3. **扩展规则**：随着项目发展，添加新的规则和模板

## 六、最佳实践

1. ✅ **保持模板简洁**：只包含核心模式，避免过度复杂
2. ✅ **添加注释**：详细的中文注释帮助 AI 理解意图
3. ✅ **版本控制**：将模板和规则纳入 Git 管理
4. ✅ **团队共享**：确保团队成员都使用相同的模板
5. ✅ **定期更新**：随着项目演进，及时更新模板

## 七、示例：创建界面跳转模板

创建 `.cursor/templates/navigation_template.md`：

```markdown
# 界面跳转模板

## 标准跳转模式

```cpp
// 跳转前验证
if (!validateParams(params)) {
    logError("参数验证失败");
    return;
}

// 记录跳转日志
logNavigation(fromPage, toPage, params);

// 执行跳转
NavigationService::navigate(toPage, params);
```

## 注意事项
- 必须进行参数验证
- 必须记录日志
- 使用统一的 NavigationService
```

---

**下一步**：根据你的具体项目，我可以帮你创建这些模板文件。请告诉我你的项目使用什么技术栈（如 C++、Java、JavaScript 等）以及具体的固定模式。




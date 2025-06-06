# 农夫和牛的实体类
class Bean:
    def __init__(self):
        self.current_dir_index = 0
        self.current_point = [0, 0]

# 移动的偏移量
offset = [[-1, 0],  # 北（上）
          [0, 1],   # 东（右）
          [1, 0],   # 南（下）
          [0, -1]]  # 西（左）

# 地图
game_map = [['' for _ in range(10)] for _ in range(10)]

# 记录历史状态，避免无限循环
visited = {}
cnt = 0

# 检查是否可以移动到指定位置的函数
def can_move(x, y):
    return 0 <= x < 10 and 0 <= y < 10 and game_map[x][y] != '*'

def main():
    global cnt
    F = Bean()
    C = Bean()

    # 读取地图
    for i in range(10):
        line = input().strip()
        for j in range(10):
            game_map[i][j] = line[j]
            if game_map[i][j] == 'F':
                F.current_point[0] = i
                F.current_point[1] = j
            elif game_map[i][j] == 'C':
                C.current_point[0] = i
                C.current_point[1] = j

    # 检查初始状态是否已经相遇
    if F.current_point[0] == C.current_point[0] and F.current_point[1] == C.current_point[1]:
        print(0)
        return

    while True:
        # 移动F
        next_fx = F.current_point[0] + offset[F.current_dir_index][0]
        next_fy = F.current_point[1] + offset[F.current_dir_index][1]

        if not can_move(next_fx, next_fy):
            # 不能前进，顺时针转90度
            F.current_dir_index = (F.current_dir_index + 1) % 4
        else:
            # 正常前行
            F.current_point[0] = next_fx
            F.current_point[1] = next_fy

        # 移动牛
        next_cx = C.current_point[0] + offset[C.current_dir_index][0]
        next_cy = C.current_point[1] + offset[C.current_dir_index][1]

        if not can_move(next_cx, next_cy):
            # 不能前进，顺时针转90度
            C.current_dir_index = (C.current_dir_index + 1) % 4
        else:
            # 正常前行
            C.current_point[0] = next_cx
            C.current_point[1] = next_cy

        cnt += 1

        # 检查是否相遇
        if F.current_point[0] == C.current_point[0] and F.current_point[1] == C.current_point[1]:
            print(cnt)
            return

        # 检查当前状态是否已访问过（在移动之后检查）
        fx, fy = F.current_point[0], F.current_point[1]
        cx, cy = C.current_point[0], C.current_point[1]
        fd, cd = F.current_dir_index, C.current_dir_index
        
        state = (fx, fy, cx, cy, fd, cd)
        
        if state in visited:
            print(0)  # 永远不会相遇
            return
        
        # 标记当前状态为已访问
        visited[state] = True

if __name__ == "__main__":
    main() 
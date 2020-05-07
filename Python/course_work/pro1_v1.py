def main():
    """find and return the solution to red sea problem with least steps"""

    def legal(state):
        """judge whether the given state is legal"""
        if state[0] != state[1]:
            for i in range(2, 8):
                if state[1] == state[i]:  # 这步判断法老在无moses下与其余共处的illegal。
                    return False
        if state[2] != state[3] or state[2] != state[4]:
            if state[5] == state[3] or state[5] == state[4]:
                return False
        if state[5] != state[6] or state[5] != state[7]:
            if state[2] == state[6] or state[2] == state[7]:
                return False
        return True

    def legal_generate():
        """generate all legal states in this puzzle

        return a two dimentional list, the inner lists are legal states
"""
        nonlocal legal_times
        all_legal_states = []
        for a in range(2):
            for b in range(2):
                for c in range(2):
                    for d in range(2):
                        for e in range(2):
                            for f in range(2):
                                for g in range(2):
                                    for h in range(2):
                                        if legal([a, b, c, d, e, f, g, h]):
                                            all_legal_states.append(
                                                [a, b, c, d, e, f, g, h])
                                            legal_times += 1
        return all_legal_states

    def legal_move(i_state: list, e_state: list):
        """judge whether a move between two states is a legal move."""
        global diff
        diff = []  # stores index of difference
        for index in range(len(i_state)):  # len(i_state) == len(e_state)
            if i_state[index] != e_state[index]:
                diff.append(index)
        if len(diff) > 2:
            return False
        # int here refer to index in list all.
        if 0 not in diff and 1 not in diff and 2 not in diff and 5 not in diff:
            if 3 in diff or 4 in diff or 6 in diff or 7 in diff:  # This excludes those who can not use the boat
                return False
        return True

    def legal_move_generator():
        """return a list of list, containing all legal move"""
        legal_moves = []
        legal_states = legal_generate()  # 调用上面定义的函数来获得所有legal states 组成的list.
        for init_index in range(len(legal_states)):  # index 是state的index
            for end_index in range(init_index+1, len(legal_states)):
                if legal_move(legal_states[init_index], legal_states[end_index]):
                    legal_moves.append([end_index, init_index])
                    if len(diff) == 1:
                        if legal_states[end_index][diff[0]] == 1:
                            continue
                    # 如果一个move legal， 那么反向move也legal
                    legal_moves.append([init_index, end_index])
        return legal_moves

    def connectable(move1: list, move2: list):
        if move1 == move2.reverse():
            return False
        if move1[1] == move2[0]:
            return True

    def solution_generator():
        this_move = []
        runtimes = 0
        solutions = []
        all_moves = legal_move_generator()
        next_move = []
        # initiallize
        for any_solution in solutions:
            while ([9, 21] not in any_solution) or ([16, 21] not in any_solution):
                if runtimes == 0:
                    first_move = [
                        tmoves for tmoves in all_moves if tmoves[0] == 0]
                    this_move = first_move  # 0是初始状态条件
                    # 三维list，第二层为某个solution，第三层为step
                    solution = [[first_step] for first_step in first_move]
                else:
                    this_move = next_move
                    for pre_move in this_move:
                        for nmoves in all_moves:
                            if nmoves[0] == pre_move[1] and nmoves.reverse() != pre_move:
                                next_move = nmoves
            # 针对前一步的所有合法移动，遍历检索所有合法移动，并匹配出连续的下一步
            # 避免重复循环回头路，两步间合法条件是两步是连续的 pre_move == this move , nmoves是 next_move的元素.
                            for possible_solutions in solution:  # 下面是处理solution的记录。
                                # 可连接
                                if possible_solutions[len(possible_solutions)-1][1] == nmoves[0]:
                                    possible_solutions.append(nmoves)
                                    print(solutions)

        runtimes += 1
        return solutions

    all = ['Mos', 'Pha', 'Aha', 'Jez', 'ser1', 'Ana', 'Sap', 'ser2']
    legal_times = 0
    print("一共有{}合法情况如下。".format(legal_times))

    n = 0
    for state in legal_generate():
        print("{}:{}".format(n, state))
        n += 1
    print("一共有{}种有效移动如下".format((len(legal_move_generator()))))
    print(legal_move_generator())
    start = [0, 0, 0, 0, 0, 0, 0, 0]
    end = [1, 1, 1, 1, 1, 1, 1, 1]
    print(solution_generator())


main()

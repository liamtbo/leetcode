
class Solution(object):
    def simplifyPath(self, path):
        str_stack = ["/"]
        path = path.split("/")
        for dir in path:
            if dir == "..":
                if len(str_stack) != 1:
                    str_stack.pop()
            elif dir == ".":
                continue
            elif len(dir) > 0:
                str_stack.append(dir + "/")

        # print(str_stack)
        str_stack = "".join(str_stack)
        if len(str_stack) > 1: str_stack = str_stack[:-1]
        return str_stack
    

tmp = Solution().simplifyPath("/home/user/Documents/../Pictures")
print(tmp)
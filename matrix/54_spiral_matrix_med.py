class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        output = []
        cell_count = 0

        x, y = 0, 0
        top_bottom = len(matrix[0])
        left_right = len(matrix) - 1
        total_cells = len(matrix) * len(matrix[0]) # base case
        while 1:
            for i in range(top_bottom):
                output.append(matrix[x][y + i])
                cell_count += 1
            y += i
            x += 1
            top_bottom -= 1

            if cell_count == total_cells: break

            for i in range(left_right):
                output.append(matrix[x + i][y])
                cell_count += 1
            x += i
            y -= 1
            left_right -= 1

            if cell_count == total_cells: break
            
            for i in range(top_bottom):
                output.append(matrix[x][y - i])
                cell_count += 1
            y -= i
            x -= 1
            top_bottom -= 1

            if cell_count == total_cells: break

            for i in range(left_right):
                output.append(matrix[x - i][y])
                cell_count += 1
            x -= i
            y += 1
            left_right -= 1

            if cell_count == total_cells: break


        return output
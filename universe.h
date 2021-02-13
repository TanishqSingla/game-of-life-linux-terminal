class Universe
{
private:
    int row;
    int col;
    int cells[1000][1000];
    bool is_ok(int n)
    {
        return n % 2 == 0 || n % 7 == 0;
    }

public:
    Universe()
    {
        row = 32;
        col = 32;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (is_ok(i + j) || is_ok(i + j))
                    cells[i][j] = 1;
                else
                    cells[i][j] = 0;
            }
        }
    }

    void tick()
    {
        int count = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                count = 0;
                count += cells[i - 1][j - 1];
                count += cells[i - 1][j];
                count += cells[i - 1][j + 1];
                count += cells[i][j - 1];
                count += cells[i][j + 1];
                count += cells[i + 1][j - 1];
                count += cells[i + 1][j];
                count += cells[i + 1][j + 1];

                if (count < 0 || count > 8)
                    count = 0;

                if (cells[i][j] == 1 && count < 2)
                    cells[i][j] = 0;
                else if (cells[i][j] == 1 && (count == 2 || count == 3))
                    cells[i][j] = 1;
                else if (cells[i][j] == 1 && count > 3)
                    cells[i][j] = 0;
                else if (cells[i][j] == 0 && count == 3)
                    cells[i][j] = 1;
            }
        }
    }

    // void render()
    // {
    // 	for (int i = 0; i < row; i++)
    // 	{
    // 		std::cout << "\t";
    // 		for (int j = 0; j < col; j++)
    // 		{
    // 			cells[i][j] ? std::cout << "■ " : std::cout << "□ ";
    // 		}
    // 		std::cout << std::endl;
    // 	}
    // }
};
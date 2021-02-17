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
                int north = i == 0 ? row - 1 : i - 1;
                int south = i == row - 1 ? 0 : i + 1;
                int west = j == 0 ? col - 1 : j - 1;
                int east = j == col - 1 ? 0 : j + 1;

                count += cells[north][west];
                count += cells[north][j];
                count += cells[north][east];
                count += cells[i][west];
                count += cells[i][east];
                count += cells[south][west];
                count += cells[south][j];
                count += cells[south][east];
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
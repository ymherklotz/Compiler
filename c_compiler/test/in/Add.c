int main() {
	int x = 8;
	int y = 29;
	int z = 84;

	{
		{
			z = x + y + x + y - x;
		}
	}
	
	return z;
}
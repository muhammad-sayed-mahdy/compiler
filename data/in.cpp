int half(int x)
{
	return x/2;
}

int main() 
{
    int t = 2;
    while (t--)
    {
        int n = 2;
        bool found = 0;
        for (int i = 0; i < n && !found; i+=1)
        {
            int num = 9;
            int s = half(num);
            if (s*2 == num)
			{
                found = 1;
				break;
			}
        }
        if (found)
			print 'Y';
		else
			print 'N';
    }
    
    return 0;
}
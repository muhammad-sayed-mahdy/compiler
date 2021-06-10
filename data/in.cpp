void main()
{

  int b = 5;
  for (int i = 0; i < 10; i--)
  {
    int b = 10;
  }
  int x = 3;
  int y = x++ + 2*3 + ++x*4;

  while (x < 20)
  {
    x++;
    b = 3;
  }

  x = 0;

  do
  {
    x++;
  } while (x < 20);

  switch (x)
  {
  case 1:
    x = 10; 
    break;

  default:
    break;
  }
}
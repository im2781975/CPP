/*** 1A ***/
//a rectangular shape with the size n × m meters.pave the Square with square granite Tile
//.which are is a * a.Count the least number of Tile to cover the square
void TheatreSquare(){
    int x, y, a; cin >> x >> y >> a;
    /*int r1 = x / a;
    int r2 = y / a;
    if(x % a != 0)
        r1++;
    if(y % a!= 0)
        r2++;
    cout << r1 * r2; */
    //cout << ceil(1.0 * (x / a)) * ceil(1.0 * (y / a));
    //cout << ((x + a - 1)/ a) * ((y + a - 1)/ a);
    //cout << (x / a + (x % a != 0)) * (y / a + (y % a != 0))
    if(a >= x && a >= y)
        cout << 1 << "\n";
    else if(x % a == 0 && y % a == 0)
        cout << (x / a) * (y / a) << "\n";
    else if(x % a != 0 && y % a != 0)
        cout << (x / a + 1) * (y / a + 1) << "\n";
    else if(x % a == 0 && y % a != 0)
        cout << (x / a) * (y / a + 1) << "\n";
    else if(x % a != 0 && y % a == 0)
        cout << (x / a + 1) * (y / a) << "\n";
}

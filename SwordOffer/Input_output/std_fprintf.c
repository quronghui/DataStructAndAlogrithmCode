// fprintf()的用法：指定的format(格式)发送信息(参数)到由stream(流)指定的文件.
// 因此fprintf()可以使得信息输出到指定的文件.
void std_fprintf()
{
    // (1) stream流需要给出其实际的路径
    int i = 10;
    double fp = 1.5;
    char s[] = "this is a string";
    char c = '\n';
    FILE *stream = fopen( "/home/quronghui/CLionProjects/9.8_practicing/fprintf.out", "w" );
    fprintf( stream, "%s%c", s, c );
    fprintf( stream, "%d\n", i );
    fprintf( stream, "%f\n", fp );
    fclose( stream );
    system( "type /home/quronghui/CLionProjects/9.8_practicing/fprintf.out" );
}




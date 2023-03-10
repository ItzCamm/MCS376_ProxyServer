/* echo.c - read and echo text lines until client closes
 connection */

void echo(int connfd){
    size_t n;
    char buf[MAXLINE];
    rio_t rio;

    Rio_readinitb(&rio, connfd);
    while((n = Rio_readlineb(&rio, buf, MAXLINE)) != 0) {
        printf("server received %d bytes: %s", (int)n, buf);
		Rio_writen(connfd, buf, n);
    }
}

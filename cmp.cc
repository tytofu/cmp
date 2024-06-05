#include <cstdlib>
#include <cstring>
#include <strings.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
using namespace std;
int main(int argc, char *argv[]) {
  // 1.如果输入命令行参数个数不对,则以-1退出码退出进程
  if (2 != argc)
    exit(-1);
  char *file = strdup(argv[1]);
  /*2.获取文件后缀
   * 2.1.argv数组中下标为1的数据元素保存文件名称
   * 2.2.利用strtok函数获取文件后缀并保存到自定义的字符数组中*/
  strtok(argv[1], ".");
  char *file_suffix = strtok(NULL, ".");
  pid_t pid = fork();
  if (0 == pid) {
    // 判断文件后缀
    if (!strcasecmp(file_suffix, "c")) {
      // 执行程序替换
      execlp("gcc", "gcc", "-std=c99", "-Wall", file, "-o",
             "/home/tinytofu/.local/bin/tf", NULL);
      exit(-1);
    } else if (!strcasecmp(file_suffix, "cc")) {
      // 执行程序替换
      execlp("g++", "g++", "-std=c++11", "-Wall", file, "-o",
             "/home/tinytofu/.local/bin/tf", NULL);
      exit(-1);
    } else if (!strcasecmp(file, "cpp")) {
      // 执行程序替换
      execlp("g++", "g++", "-std=c++11", "-Wall", file, "-o",
             "/home/tinytofu/.local/bin/tf", NULL);
      exit(-1);
    }
  }
  pid_t ret = waitpid(pid, NULL, 0);
  if (ret > 0) {
    free(file);
    exit(0);
  } else
    exit(-1);
}

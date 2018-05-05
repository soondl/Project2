#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

struct stat stat1, stat2;
struct tm *time1, *time2;

void filestat1(void);
void filestat2(void);
void filetime1(void);
void filetime2(void);
void sizecmp(void);
void blockcmp(void);
void datecmp(void);
void timecmp(void);

int main(void)
{
	filestat1();
	filestat2();
	filetime1();
	filetime2();
	sizecmp();
	blockcmp();
	datecmp();
	timecmp();
}

//파일 1의 정보를 가져오는 함수 작성
void filestat1(void)
{
  const char* filename = "./text1";

  if (stat(filename, &stat1)) {
    puts("invalid filename");
  }
}

//파일 2의 정보를 가져오는 함수 작성
void filestat2(void)
{
  const char* filename = "./text2";

  if (stat(filename, &stat2)) {
    puts("invalid filename");
  }
}

//파일 1의 시간 정보를 가져오는 함수 작성
void filetime1(void)
{
	static struct tm t1;
	t1 = *(localtime(&stat1.st_mtime));
	time1 = &t1;
}

//파일 2의 시간 정보를 가져오는 함수 작성
void filetime2(void)
{
	static struct tm t2;
	t2 = *(localtime(&stat2.st_mtime));
	time2 = &t2;
}

//두 개의 파일 크기를 비교하는 함수 작성
void sizecmp(void)
{
}

//두 개의 파일 블락 수를 비교하는 함수 작성
void blockcmp(void)
{
}

//두 개의 파일 수정 날짜를 비교하는 함수 작성
void datecmp(void)
{
	time_t t1, t2, diff;
	struct tm tm1, tm2;

	t1 = stat1.st_mtime;
	t2 = stat2.st_mtime;

	tm1 = *time1;
	tm2 = *time2;

	tm1.tm_sec = 0;
	tm1.tm_min = 0;
	tm1.tm_hour = 0;
	tm2.tm_sec = 0;
	tm2.tm_min = 0;
	tm2.tm_hour = 0;

	t1 = mktime(&tm1);
	t2 = mktime(&tm2);

	diff = t1 - t2;

	printf("date compare\n");

	if(diff == 0) {
		printf("same date\n");
	}
	else if(diff < 0) {
		printf("text1 is early\n");
	}
	else {
		printf("text2 is early\n");
	}
}

//두 개의 파일 수정 시간을 비교하는 함수 작성
void timecmp(void)
{
	time_t t1, t2, diff;
	t1 = stat1.st_mtime;
	t2 = stat2.st_mtime;
	diff = t1 - t2;

	printf("date compare\n");

	if(diff == 0) {
		printf("same time\n");
	}
	else if(diff < 0) {
		printf("text1 is early\n");
	}
	else {
		printf("text2 is early\n");
	}
}

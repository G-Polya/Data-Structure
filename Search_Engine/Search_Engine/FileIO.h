#pragma once

//1. 파일전체 읽어오기
//3. 저장된 문장에서 strtok로 쪼갬(while문)

//1. I want to dance, for example, Locking
//	 I want to sleep.
//   I want to be popular 라고 하면

//2. I//want//to//dance,//for example,//Locking
//   I//want//to//sleep.
//   I//want//to//be//popular
void read_tok(char *fname);

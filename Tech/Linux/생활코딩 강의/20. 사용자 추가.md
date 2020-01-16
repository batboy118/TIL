# 20. 사용자 추가

### add user

sudo useradd (-m) 이름` : -m을 써주면 home 디렉토리에 유저 디렉토리까지 생성해줌



`exit`

`이름`



**패스워드 설정**

`sudo passwd 이름`



**sudo 권한 부여**

`adduser 닉네임 sudo`

또는

`sudo usermod -a -G sudo 이름`  // sudo그룹에 추가






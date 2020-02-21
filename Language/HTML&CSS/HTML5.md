# HTML5

HTML[ Hyper Text Markup Language ]은 웹페이지를 기술하기 위한 마크업 언어로, 사용자(클라이언트)가 보는 웹 페이지의 내용과 구조를 담당하는 언어로 태그를 통해 웹 페이지를 구조화 시킨다.

![https://k.kakaocdn.net/dn/VJohj/btqx8KZmuKr/4Q5qM5VI3cislGG5cusvm0/img.png](https://k.kakaocdn.net/dn/VJohj/btqx8KZmuKr/4Q5qM5VI3cislGG5cusvm0/img.png)

전통적으로, HTML, CSS, Javs Script를 모두 이용하여 웹 프론트엔드를 개발한다.

> HTML : Content
>
> CSS : Presentation
>
> JS : Behavior



## 기본형태

![https://k.kakaocdn.net/dn/b9jb7j/btqx9yKGmkO/BD9OXDAWyFzYcu6Nq7f430/img.png](https://k.kakaocdn.net/dn/b9jb7j/btqx9yKGmkO/BD9OXDAWyFzYcu6Nq7f430/img.png)

html : Document

head : 화면에 어떻게 보이게 할지 추가적인 정보를 담고 있음 (메타정보)

body : 실제로 화면에 보여지는 내용

```html
<!DOCTYPE html>
<html>
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width">
  <title>제목</title> // 상단에 표시되는 내용
</head>
<body>
Hello world
</body>
</html>
```



- **출력 결과**

  Body에 있는 내용이 출력이 됨 : Hello world



- **태그 설명**

  - **\<!DOCTYPE html>** : 브라우저에게 이 문서를 HTML 문서임을  알려준다. 

  > Q : 왜 \<!DOCTYPE html>은 태그를 닫지 않는가?
  >
  > A : self-contained 태그로 그 자체로 정보를 제공하기 때문이다.

  - **\<html>   \</html>** : 문서를 열고 닫는다. 사이에는 head와 body가 올 수 있다.

  - **\<head>  \</head>** : 헤드는 유저에게 보이지 않는다. 웹사이트에 관한 필요한 정보를 제공해주는 역할을 한다. 반드시 head를 닫아야 주어야 어디까지가 헤드인지 파악이 가능하다. 

  > 헤드에 사용될 수 있는 태그 예시
  >
  > - \<title> : 제목 태그 : 브라우저 상단의 탭에 이름이 표시
  >   - \<title> This is my title \</title>

  - **\<body>  \</body>** : 바디는 화면에 표시되는 내용이고, 마찬가지로 반드시 닫아주어야 한다.

  > 바디에 사용할 수 있는 태그 예시
  >
  > - \<h1> : 큰 타이틀
  > - \<h2> : 작은 타이틀
  > - ....



## Meta

meta 태그는 extra information을 나타낼 때 사용된다. 헤드안에서 작성해야한다.

`<meta charset=" ">`

메타 태그에 charset이라는 것이 있는데  문서의 문자 인코딩 방식을 결정한다. 한국에서는 utf-8이 많이 쓰지이만, 만약 아랍어나 러시아어를 출력해야 한다면, 다른 인코딩을 사용해야 한다.

**메타 name에 따라 다른 정보를 제공할 수 있다.**

`<meta name="description" contents="Hello, There">`

메타의 이름을 description이라고 지정해주면 contets가 검색엔진에서 검색했을 때 웹사이트에 대한 설명 형태로 보인다.

`<meta name="author" contents="batboy118">`

작성자의 정보를 제공해 준다.



```html
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
        <meta name="description" contents="Hello, There">
        <meta name="author" contents="batboy118">
    </head>
    <body>
    </body>
</html>
```



## Semantic & Non Semantic Tag

- **Semantic Tag**: 의미가 있는 태그 (태그만 보고도 어떤것을 의미하는지 알 수 있는 태그)

  > 예)
  >
  > `<h1>`
  >
  > `<section>`
  >
  > `<header>`
  >
  > `<article>`

- **Non Semantic Tag**: 의미가 없는 태그 (안에 무슨 내용이 들어가는지 태그만 보고 알 수 없음)

  > 예)
  >
  > `<span>` : short (텍스트를 위한 컨테이너, 단순한 텍스트를 쓸 컨테이너가 필요한 경우)
  >
  > `<div>` : division  (박스와 같은 컨테이너)



## Tag에 이름 부여하기 (ID or Class)

```html
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
        <meta name="description" contents="Hello, There">
        <meta name="author" contents="batboy118">
        <title>This is a title</title>
    </head>
    <body>
        <section>
            <header id="headerNumnerOne" class="defaultHeader">
                <h1>Title of a section</h1>
            </header>  
        </section>
        
        <div>
            <header id = "differentHeader" class="defaultHeader">Title of the unkown container</header>
        </div>
    </body>
</html>
```

css로 특정 부분에 스타일을 지정해 주어야 할 때 이름(ID와 class)이 사용된다.

- ID : 각 element마다 ID는 한개만 가질 수 있다. ID는 고유한 값

  `<header id = "headerNumnerOne">`

  ` <header id = "differentHeader">`

- Class : 여러번 사용 될 수 있다. 여러개를 하나의 그룹처럼 다룰 수 있다.

  `<header class="defaultHeader">`

- ID와 Class를 같이 써서, 동일하게 적용할 부분과 차별을 두어야 할 점을 CSS로 각각 설정 할 수도 있다. class는 공유하지만, id는 따로 사용하기 때문에 class로 공통 설정을 하고 id로 개별 설정을 할 수 있다.

  `<header id = "headerNumnerOne" class="defaultHeader">`

  ` <header id = "differentHeader" class="defaultHeader">`



## 태그, 속성 값 예

예 : <a href="[batboy.tistory.com](http://batboy.tistory.com)">블로그로 갑니다.</a>

태그 : <a> ~~~ </a>

속성 : href="[batboy.tistory.com](http://batboy.tistory.com)"

속성 값 : href

텍스트 : 블로그로 갑니다

<a href="batboy.tistory.com">블로그로 갑니다.</a>

를 Body에 넣으면 해당 URL로 링크를 걸어주는 Text를 생성해줌.

```html
<!DOCTYPE html>
<html>
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width">
  <title>HAHAHA</title>
</head>
<body>
Hellow world
  <a href="batboy.tistory.com">블로그로 갑니다.</a>
</body>
</html>
```

- 출력 결과

Hellow world [블로그로 갑니다.](https://null.jsbin.com/batboy.tistory.com)

기본적으로 HTML에 대해서 알아보았습니다.
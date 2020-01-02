# Basic Usage of CSS

파일 이름 : styles.css



## CSS 구성

CSS는 두 가지 파트가 있다.

1. property : 어떤 스타일을 줄지 결정함
2. selector : 스타일을 지정해 줄 대상을 특정함 (태그, ID, Class 등 모든 것이 셀렉터가 될 수 있다.)

```css
h1 {
	property-name : value;
    property-name : value;
    property-name : value;
}

#nameOfID{
    ...
}

.nameOfClass{
    ...
}
```

- selector

  **태그 이름**, **#ID이름**, **.클래스이름** 

- property

  **괄호 내부에 있는 특성** 

  반드시 ; 으로 끝나야 함



## Mixing CSS with HTML

```html
<!DOCTYPE html>

<html lang="en">
	<head>
      <meta charset="UTF-8">
      <meta name="viewport" content="width=device-width, initial-scale=1.0">
      <meta http-equiv="X-UA-Compatible" content="ie=edge">
      <title>Home Me</title>
	</head>
    
    <body>
        <h1>Home Title</h1>
        <p>This is Love. Love is good.Feeling good is great.</p>
        <a ref='#'>Fake link</a>
    </body>
</html>
```

위 html코드를 가지고 예시를 들어 보겠다.



html과 css를 연결하는 방법은 2가지가 있다.

1. inline : html 파일 자체에 css style을 작성 할 수 있다.

2. external : 

   <예시>

   indext.html과 contact-me.html 두 파일이 있다고 가정하고, 두 가지 방식의 css를 적용해 보겠다.

   

   - inline : html 파일에 \<style>태그를 넣어 배경색을 빨간색으로 바꾸는 코드
     - index의 배경만 빨간색이 된다. 즉, 해당 파일에 있는 요소들에만 적용된다.

   - external : 

   <index.html>

   ```html
   <!DOCTYPE html>
   
   <html lang="en">
   	<head>
         <meta charset="UTF-8">
         <meta name="viewport" content="width=device-width, initial-scale=1.0">
         <meta http-equiv="X-UA-Compatible" content="ie=edge">
         <title>Home</title>
   	 
         <!-- External (awesome) -->
    	  <link href="style.css"  rel="stylesheet">
           
         <!-- Inline (not cool)-->
         <style>
             body{
                 background-color :res;
             }
         </style>
   
   	</head>
       
       <body>
           <h1>Home Title</h1>
           <p>This is Love. Love is good.Feeling good is great.</p>
           <a href="contact-me.html">Fake link</a>
       </body>
   </html>
   ```

   <contact-me.html>

   ```html
   <!DOCTYPE html>
   
   <html lang="en">
   	<head>
         <meta charset="UTF-8">
         <meta name="viewport" content="width=device-width, initial-scale=1.0">
         <meta http-equiv="X-UA-Compatible" content="ie=edge">
         <title>Contact-me</title>
           
         <!-- External (awesome) -->
    	  <link href="style.css"  rel="stylesheet">
           
   	</head>
       
       <body>
           <h1>"Contact-me Title</h1>
       </body>
   </html>
   ```

   <styles.css>  :  external css

   `<link rel="stylesheet" href="style.css">`을 적용하고 싶은 곳에다가 써주어야 한다.

   **의미** 

   - href파일을 rel(relationship)관계로 link한다.

   href와 rel순서가 바뀌어도 됨

   ```css
   h1 {
   	color : green;
   }
   ```

   

## Box Model

HTML로 구성된 element들은 Box로 취급된다.

box에는 4가지 요소가 있다.

![box-model.gif](https://github.com/nomadcoders/kakao-clone-examples/blob/master/02-box-model/box-model.gif?raw=true)

1. Content : 내용
2. Padding : 컨텐츠와 보더 사이의 간격 
3. Boarder : 박스의 경계(외부 틀)
4. Margin : 다른 박스와의 간격

```html
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <meta http-equiv="X-UA-Compatible" content="ie=edge">
  <title>Box Model</title>
  <style>
    body,html{
      padding: 0;
      margin: 0;
      background-color: green;
      height: 100%;
    }
    .box{
      background-color: yellow;
      width: 50%;
      height:50%;
      padding:30px; /* all sides */
      padding:30px 20px; /* top bottom | left right */
      padding:20px 10px 5px 2px; /* top | bottom | left | right */
      margin:30px; /* all sides */
      margin:30px 20px; /* top bottom | left right */
      margin:20px 10px 5px 2px; /* top | bottom | left | right */
      /*margin-top : 50px;
        margine-legt : 30px;
        이런식으로도 표현 가능
        */
    }
    .inside-box{
      background-color: blue;
      width:50%;
      height: 50%;
      border:5px dashed red; /* border-width | border-style | border-color */
    }
  </style>
</head>
<body>
    <div class="box">
      <div class="inside-box"></div>
    </div>
</body>
</html>
```

<설명>

- body 

  box안에 inside box를 넣는다.

  ```html
  <div class="box">
        <div class="inside-box"></div>
  </div>
  ```

  기본 padding과 마진은 0, 배경은 green, 높이는 전체를 지정함

  ```css
  body,html{
        padding: 0;
        margin: 0;
        background-color: green;
        height: 100%;
  }
  ```

- box

  width와 height를 body 전체의 50%로 설정하고, contents + padding 전체를 노란색

  ```css
  .box{
        background-color: yellow;
        width: 50%;
        height:50%;
  }
  ```

- inside box

  width와 height를 **box의**  50%로 설정하고, contents + padding 전체를 파란색으로 함

  ```css
  .inside-box{
        background-color: blue;
        width:50%;
        height: 50%;
  }
  ```



## Display : Inline vs Block vs Inline Block

```html
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <meta http-equiv="X-UA-Compatible" content="ie=edge">
  <title>Inline Example</title>
  <style>
  .box{
    background-color: red;
    width:200px;
    height:200px;
    border:2px solid black;
    display: inline-block; /* block or inline or inline-block */
  }
  </style>
</head>
<body>
  <span class="box">1</span>
  <span class="box">1</span>
  <span class="box">1</sspan>
</body>
</html>
```

![소스 이미지 보기](https://i.stack.imgur.com/mGTYI.png)

박스는 **inline-block**이나 **block** 중 하나에 해당해야 한다.

- block (defalut) : 하나의 가로줄을 하나의 박스가 차지하는 것을 의미함. 즉, 옆에 새로운 element가올수 없고, 아래로 새로운 블럭이 쌓이게 된다.

- inline-block : 새로운 박스가 옆으로 쌓이게 된다.

**inline** : box가 아니라 텍스트처럼 적용이 된다.

- width, height(contents영역의 크기)를 무시하게 됨
- padding이나 마진, boader는 설정 가능하다.



## Position Property

```html
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <meta http-equiv="X-UA-Compatible" content="ie=edge">
  <title>Position</title>
  <style>
    body,html{
      height: 100%;
      margin:0;
      padding:0;
    }
    body{
      height: 400%;
      background-color: red;
    }
    /* Position Fixed

    #boxOne{
      height:300px;
      width:300px;
      background-color: yellow;
      position:static;
    }
    #boxTwo{
      height:300px;
      width:100%;
      background-color: green;
      position:fixed;
      bottom:30%;
      left:0;
    }*/
    /* Absolute */
    .abs-box{
      width:400px;
      height: 400px;
      background-color: yellow;
      position: relative; /* Remember to put relative here or the child will go to the body*/
    }
    .abs-child{
      width:100px;
      height: 100px;
      background-color: green;
      position: absolute;
      right:10px;
      top:10px;
    }
  </style>
</head>
<body>
  <div class="abs-box">
    <div class="abs-child"></div>
  </div>
  <!-- Position Fixed
  <div id="boxOne">
    <div class="box-child"></div>
  </div>
  <div id="boxTwo">
    <div class="box-child"></div>
  </div> -->
</body>
</html>
```

<설명>

- 브라우저 기본 값을 상쇄 

  높이를 100%, 마진과, 패딩을 0으로 설정

  ```css
  body,html{
        height: 100%;
        margin:0;
        padding:0;
  }
  ```

- body 설정

  높이를 400%로해서 스크롤 가능

  ```css
  body{
        height: 400%;
        background-color: red;
  }
  ```

- **position**

  1. static (default) :

     element를 원하는 곳에 넣으면 무슨일이 있든지 그 자리에 위치한다는 의미이다. 즉 절대적인 위치를 결정하는 것이다.

     ```css
      #boxOne{
           height:300px;
           width:300px;
           background-color: yellow;
           position:static;
         }
     ```

  2. fixed

     스크롤을 해도 항상 동일한 위치에 박스가 존재함. (오버랩 된다.)

     아래 코드에서는 스크롤을 맨위로 올릴 때 boxOne아래에 boxTwo가 존재하지만, 스크롤을 내려도 화면에 표시되는 boxTwo의 위치는 동일하고, boxOne은 절대적인 위치가 고정이 되기 때문에 스크롤하면 안보이게 된다. 

     화면에 표시되는 절대값을 지정해 줄 수도 있다.

     top, bottom, left, right의 값을 설정해서 지정 가능.

     > right : 0 ; 이면 화면 우측에 붙게 된다.
     >
     > bottom : 10px; 이면 화면 아래에서 10px 떨어진 곳에 표시 된다.

     ```css
      #boxOne{
           height:300px;
           width:300px;
           background-color: yellow;
           position:static;
         }
     #boxTwo{
           height:300px;
           width:100%;
           background-color: green;
           position:fixed;
           bottom:30%;
           left:0;
         }
     ```

  3. absolute & relative 

     absolute는 부모 중 relative 인것의 상대적인 포지션을 잡는다.

     abs-box안에 abs-child가 있다고 가정하고 살펴보면, absolute는 element와 관계있는 element(부모box)가 relative 포지션인지 살펴보고 이에 상응해서 포지션을 결정한다.

     ```html
     <div class="abs-box">
         <div class="abs-child"></div>
     </div>
     ```

     아래 경우에는 abs-box가 relative 포지션이 아니기 때문에 부모의 위치를 찾지 못하고 body를 기준으로 위치를 잡게 된다. **(body는 기본적으로 relative 포지션을 가진다. )**

     ```css
     .abs-box{
           width:400px;
           height: 400px;
           background-color: yellow;
         }
     .abs-child{
           width:100px;
           height: 100px;
           background-color: green;
           position: absolute;
           right:10px;
           top:10px;
         }
     ```

     아래 경우에는 부모 박스가 relative 포지션이기 때문에 부모 박스 내부에서 상대적인 위치를 기준으로 잡는다.

     ```css
     .abs-box{
           width:400px;
           height: 400px;
           background-color: yellow;
            position: relative;/* Remember to put relative here or the child will go to the body*/
         }
     .abs-child{
           width:100px;
           height: 100px;
           background-color: green;
           position: absolute;
           right:10px;
           top:10px;
         }
     ```



## Fluid layouts with Flexbox

참고) [Flex 연습](http://flexboxfroggy.com/#ko)

```html
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <meta http-equiv="X-UA-Compatible" content="ie=edge">
  <title>Flex</title>
  <style>
  html,body{
    height: 100%;
  }
  .father{
    display: flex;
    justify-content: space-between;
    align-items: flex-start;
    flex-direction: row;
    height: 100%;
    flex-wrap:wrap;
  }
  .box{
    background-color: red;
    width: 200px;
    height: 200px;
    border:1px solid black;
    display: flex;
    /*display : inline-box;*/
    justify-content: center;
    align-items: center;
    color:white;
  }
  </style>
</head>
<body>
  <div class="father">
    <div class="box">1</div>
    <div class="box">2</div>
    <div class="box">3</div>
    <div class="box">4</div>
    <div class="box">5</div>
    <div class="box">6</div>
    <div class="box">7</div>
    <div class="box">8</div>
    <div class="box">9</div>
    <div class="box">10</div>
  </div>
</body>
</html>
```

<설명>

box class를 inline-block으로하고, 여러 박스을 생성하면 박스가 옆으로 붙다가 더 이상 공간이 없다면, 다음 줄로 넘어가서 박스를 표시하게 되는 문제가 있다. 하지만, 공간이 부족한 경우 한 줄에서 좌우 마진이 다른 경우가 존재한다. 자동으로 완선되는 그리드가 없기 때문에 발생하는 문제이다.

또한, 환경에 따라 마진이 다르게 보일 수 있고 화면에 표시되는 모양도 다르다. 

이런경우, inline-box가 아닌 flex를 사용하면 된다.

먼저 부모 박스를 만들고, 내부에 자식 박스를 만든다. 기존에는 자식박스에 display : inline-block; 이 있었다면, 그것을 지우고, 부모 박스에만 display : flex;를 해주면 된다. (자동으로 자식 박스들은 inline-block 처럼 출력됨)

flex는 부모박스에만 적용한다.

```css
.father{
    display: flex;
    justify-content: space-between;
    align-items: flex-start;
    flex-direction: row;
    height: 100%;
    flex-wrap:wrap;
  }
  .box{
    background-color: red;
    width: 200px;
    height: 200px;
    border:1px solid black;
    display: flex;
    /*display : inline-box;*/
    justify-content: center;
    align-items: center;
    color:white;
  }
```

- flex direction에 따라 속성도 다르게 적용된다.

  `flex-direction: row;` : **수평으로** contents 나열 (기본값)

  - `justify-content` : **수평으로** 적용되는 속성
  - ` align-items` : **수직으로** 적용되는 속성

  `flex-direction: column;` : **수직으로** contents 나열

  - `justify-content` : **수직으로** 적용되는 속성
  - ` align-items` : **수평으로** 적용되는 속성

  ``flex-direction: row-reverse;` : 수평으로 contents를 나열하지만 왼쪽부터 생성되는게 아니라 오른쪽 부터 생성된다. 1~10이 있다면, 10~1로 생성된다.

- flex를 적용하면 아래에 자식 박스가 많아도 절대로 다음 줄로 넘기지 않는다. 자식들의 사이즈를 자동으로 줄여서 한 줄에 다 들어가게 만든다. 여러 줄로 표시하고 싶다면 wrap을 사용하면 된다.

- flex는 디폴트로 no-wrap이다. wrap을 사용하지 않으면, 자식 박스들의 크기는 화면의 크기에 따라 조절 된다. 하지만,, wrap을 사용하면 자식박스들의 사이즈는 변하지 않고, 화면에 표시가능한 범위가 넘어가면 자동으로 다음 줄로 박스들은 넘겨 여러줄로 표시 할 수 있다.

  `flex-wrap:wrap;`

  `flex-wrap:no-wrap;` (기본값)

  `flex-wrap:wrap-reverse;`

  `flex-wrap:no-wrap-reverse;`



## CSS Selectors and Pseudo Selectors

```html
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <meta http-equiv="X-UA-Compatible" content="ie=edge">
  <title>Selectors and Pseudo Selectors</title>
  
  <style>
  input[required="required"]{
    background-color: red;
  }
  .box:nth-child(3n+2){
    background-color: pink;
  }
  .container > .box{
    background-color: yellow;
  }
  .box{
    border:1px solid yellow;
  }
  .box{
    background-color: green;
    display: block;
    height: 100px;
    border:1px solid black;
  }
  .child{
    width: 40px;
  }
  </style>
    
</head>
    
<body>
<div class="container">
  <div class="box">
    <div class="box child"></div>
  </div>
  <div class="box"></div>
  <div class="box"></div>
  <div class="box"></div>
  <div class="box"></div>
  <div class="box"></div>
  <div class="box"></div>
  <div class="box"></div>
  <div class="box"></div>
  <div class="box">
    <input type="password" required="required" />
    <input type="submit" required="required" />
  </div>
</div>
</body>
    
</html>
```

ID나 Class를 쓰지 않고, 원하는 요소를 선택할 수 있는 방법이 있다.

- pseudo-selector(가상 셀럭터)

  셀렉터 이지만, element가 아닌것을 의미한다.

  예) input[type=" "] 을 사용해서 특정 태그+내부 내용을 가지고 선택하여 스타일 지정 가능

  ```html
  <head>
  <style>
      input[type="submit"]{
          background-color: red;
      }
      input[type="password"]{
  		background-color: yellow;
        	border:1px solid black;
  	}
  </style>  
  </head>
  
  <body>
      <div class="box">
          <input type="password">
          <input type="submit">
      </div>
  </body>
  ```

  예) 특정 이름을 지정할 수도 있다. 아래 예시에서는 required와 abc라는 이름을 사용했다.

  ```html
  <head>
  <style>
      input[required="required"]{
          background-color: red;
      }
      input[abc="abc"]{
  		background-color: yellow;
        	border:1px solid black;
  	}
  </style>  
  </head>
  
  <body>
      <div class="box">
          <input type="password" required="required">
          <input type="submit" abc="abc">
      </div>
  </body>
  ```

- 자식 박스 중 특정 박스만 다른 스타일을 주는 방법

  - 마지막 박스에 특성 주기

    ```css
    .box: last-child{
    	    background-color: pink;
    }
    ```

  - 첫 번째 박스에 특성 주기

    ```css
    .box: first-child{
    	 background-color: pink;
    }
    ```

  - n 번째 박스에 특성 주기

    연습 : http://www.topdesignagencies.com/nth-test/
    
    ```css
    .box: nth-child(2){     /*2번째 박스에 특성 주기*/
    	 background-color: pink;
}
    ```
    
    ```css
    .box: nth-child(2n){     /*2의 배수 박스에 특성 주기*/
    	 background-color: pink;
}
    ```
    
    ```css
    .box: nth-child(3n){     /*3의 배수 박스에 특성 주기*/
    	 background-color: pink;
}
    ```
    
    ```css
    .box: nth-child(2n+1){     /*1번째 부터 시작해서 매 두번째 (홀수번째) 박스에 특성 주기*/
    	 background-color: pink;
}
    ```


- direct child (직계 자식에게만 적용됨)

  `input > .box`  : input 바로 아래에 있는 box에만 적용된다. box 밑의 box들에는 적용 안됨

- 원하는 패턴이 나왔을 때(형제)  : + 사용

  `input + .box` : input 태그 다음에 .box 클래스가 있는 경우를 모두 찾아 .box에 속성 적용

  `input + .box + .box` : input + .box + .box구조를 모두 찾아 가장 각각 마지막 box에만 속서 적용 

- class로 여러가지 속성 부여 가능

  `class = "box child"`인경우, box와 child 두개의 class를 사용하는 것과 같다. 



## Element States with CSS

```html
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <meta http-equiv="X-UA-Compatible" content="ie=edge">
  <title>CSS States</title>
  <style>
  .box{
    background-color: red;
    font-size: 40px;
  }
  .box:hover{
    background-color: pink;
  }
  .box:active{
    background-color: green;
  }
 .box:focus{
    background-color: blue;
  }
  input:focus{
    background-color:blue;
  }
  a:visited{
    color: yellow;
  }
  </style>
</head>
<body>
  <input type="text">
  <span class="box">lalalalalala</span>
  <textarea class="box">lalalalalala</textarea>
  <a href="http://kakao.com">Naver</a>
</body>
</html>
```

- hover : 화살표 대상에 올리면 hover속성이 적용됨
- active : 클릭하면 active 속성이 적용됨
- focus : 클릭하면 색이 바뀜 active와 hover보다 우선됨 (input이나 textarea와 같은 선택이 가능한 영역에 적용됨)
- visited : 한 번 눌린 링크의 속성을 변경함



# Advanced Usage of CSS

## Transitions

이동, 변경에 효과를 주는 것

```html
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <meta http-equiv="X-UA-Compatible" content="ie=edge">
  <title>Transitions</title>
  <style>
  .box{
    background-color: green;
    color:white;
    transition:all .5s ease-in-out;
  }
  .box:hover{
    background-color: red;
    color:blue;
  }
  </style>
</head>
<body>
  <span class="box">
    Text
  </span>
</body>
</html>
```

- hover, active, passived의 state에 애니메이션 효과를 준다. (visited는 적용 안됨)

  `transition : 변경할 속성 시간 애니메이션`

  - `	transition: background-color 5s ease-in-out;`  	

    백그라운드 속성이 5초안에 바뀌는 것 (ease-in-out : 생겼다가 사라지는 효과)

  - `transition:all .5s ease-in-out;`

    모든 속성을 0.5초안에 바꿈 

​	

## Transformations

```html
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <meta http-equiv="X-UA-Compatible" content="ie=edge">
  <title>Transformations</title>
  <style>
    .box{
      width: 100px;
      height: 100px;
      background: red;
      transition: transform .5s ease-in-out;
    }
    .box:hover{
      transform: rotate(1turn) scale(.5, .5);
    }
  </style>
</head>
<body>
  <div class="box"></div>
</body>
</html>
```

- transform 관련 기능 : https://developer.mozilla.org/en-US/docs/Web/CSS/transform

- rotate, scale 등 사용 가능

  20도 회전

  ```css
  transform: rotate(20deg);
  ```

  transition이랑 같이 사용하면 애니메이션 효과도 줄 수 있다.

  ```css
   .box{
        width: 100px;
        height: 100px;
        background: red;
        transition: transform .5s ease-in-out;
      }
      .box:hover{
        transform: rotate(1turn) scale(.5, .5);
      }
  ```



## Animations

```html
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <meta http-equiv="X-UA-Compatible" content="ie=edge">
  <title>Transformations</title>
  <style>
    .box{
      width: 100px;
      height: 100px;
      background: red;
      animation: 1.5s scaleAndRotateSquare infinite ease-in-out;
    }
    /*@keyframes scaleAndRotateSquare {
      from{
		transform:none;
      }
      to{
		transform: rotate(1turn) scale(.5, .5);
      }
    }*/
    @keyframes scaleAndRotateSquare {
      0%{
        transform:none;
      }
      50%{
        transform: rotate(1turn) scale(.5, .5);
        color:white;
      }
      100%{
        transform: none;
        color:blue;
      }
    }
  </style>
</head>
<body>
  <div class="box">11</div>
</body>
</html>
```

-  @keyframes 애니메이션 이름

  두 단계에서는 from, to 만 사용

  infinite를 쓰면 무한 반복, 안쓰면 새로고침할 때 마다 한번 실행

  ```css
  .box{
        width: 100px;
        height: 100px;
        background: red;
        animation: 1.5s scaleAndRotateSquare infinite ease-in-out;
      }
      @keyframes scaleAndRotateSquare {
        from{
  		transform:none;
        }
        to{
  		transform: rotate(1turn) scale(.5, .5);
        }
      }
  ```

- 여러 단계를 표시하고 싶으면, %로 구분

  ```css
  @keyframes scaleAndRotateSquare {
        0%{
          transform:none;
        }
        50%{
          transform: rotate(1turn) scale(.5, .5);
          color:white;
        }
        100%{
          transform: none;
          color:blue;
        }
      }
  ```



## Media Queries

[Using media queries](https://developer.mozilla.org/en-US/docs/Web/CSS/Media_Queries/Using_media_queries)

브라우저의 크기가 다 다름 : 넓은 화면, 좁은 화면, 스마트폰, 노트북, 태블릿 등등

```html
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <meta http-equiv="X-UA-Compatible" content="ie=edge">
  <title>Media Queries</title>
  <style>
  body{
    background-color: green;
  }
  @media screen and (min-width:320px) and (max-width:640px){
    body{
      background-color: blue;
    }
  }
  </style>
</head>
<body>
</body>
</html>
```

- `@media screen and (min-width:320px) and (max-width:640px)`

  넓이가 320 - 640 사이인 경우 아래의 속성 적용

  이것을 활용해서 반응형 웹을 만들 수 있다.
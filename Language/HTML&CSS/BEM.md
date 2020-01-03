# Methodolgies

커다란 규모의 프로젝트에는 커다란 CSS파일이 있다. CSS파일의 크기를 줄이는 방법들이 다양하게 존재 한다.

- #### [OOCSS](http://oocss.org/)

  Separating container and content with CSS “objects”

- #### [SMACSS](http://smacss.com/)

  Style-guide to write your CSS with five categories for CSS rules

- #### [SUITCSS](http://suitcss.github.io/)

  Structured class names and meaningful hyphens

- #### [Atomic](http://github.com/nemophrost/atomic-css)

  Breaking down styles into atomic, or indivisible, pieces

- #### BEM

  Blocks, Elements and Modifiers

  

# BEM

BEM의 장점 :  단순하지만, 좋은 구조를 가지고있다. 

**BEM 방법론은 ID에는 사용할 수 없고, 오직 클래스명에만 활용할 수 있다는 점**에 주의



- **Block**

  Standalone entity that is **meaningful on its own**.

  ex) `header`, `container`, `menu`, `checkbox`, `input`

- **Element**

  **A part of a block** that has no standalone meaning and is semantically tied to its block.

  ex)`menu item`, `list item`, `checkbox caption`, `header title`

- **Modifier**

  A flag on a block or element. Use them to change **appearance or behavior**.

  ex) `disabled`, `highlighted`, `checked`, `fixed`, `size big`, `color yellow`

![img](http://getbem.com/assets/github_captions.jpg)

## Button example

![img](http://getbem.com/assets/github_buttons.jpg)

평상시 상태로 노말 버튼이 있고, 두 개의 상태에 따른 버튼이 각각 있다. 우리는 블럭을 BEM방식으로 class selector단위로 버튼을 꾸밀수 있기 때문에 버튼들에게 우리가 원하는 어떠한 태그(button, a, div 등)든지 부여할 수 있다. 네이밍 룰은 **`block--modifier-value` **문법을 가진다.

- HTML

```html
<button class="button">
	Normal button
</button>
<button class="button button--state-success">
	Success button
</button>
<button class="button button--state-danger">
	Danger button
</button>
```

- CSS

```css
.button {    /*모든 button 적용됨*/
	display: inline-block;
	border-radius: 3px;
	padding: 7px 12px;
	border: 1px solid #D5D5D5;
	background-image: linear-gradient(#EEE, #DDD);
	font: 700 13px/18px Helvetica, arial;
}
.button--state-success {
	color: #FFF;
	background: #569E3D linear-gradient(#79D858, #569E3D) repeat-x;
	border-color: #4A993E;
}
.button--state-danger {
	color: #900;
}
```



## Benefits

- Modularity

  Block styles are never dependent on other elements on a page, so you will never experience [problems from cascading](http://www.phase2technology.com/blog/used-and-abused-css-inheritance-and-our-misuse-of-the-cascade/).

  You also get the ability to transfer blocks from your finished projects to new ones.

- Reusability

  Composing independent blocks in different ways, and reusing them intelligently, reduces the amount of CSS code that you will have to maintain.

  With a set of style guidelines in place, you can build a library of blocks, making your CSS super effective.

- Structure

  BEM methodology gives your CSS code a solid structure that remains simple and easy to understand.



## Key Concepts

#### **Block**

블럭이란, 기능적으로 독립적인 요소 하나하나를 의미한다. 

블럭은 behavior, templates, styles 등의 implementation을 포함하고 있다.

독립적인 블럭은 재사용이 가능하고 프로젝트 개발을 쉽게 해준다.

- Nested Structure

  블럭 내부에 다른 블럭들이 올 수 있다.

  아래 그림을 보면, 헤드블럭 안에 logo, search, auth 블럭 등이 위치해 있다.

![Head block components](https://en.bem.info/kFetIbKxQdABHhUecbic45Il0Bg.png)

블럭 요소는 클래스의 어근을 형성하고 항상 맨 앞에 위치하도록 합니다. 

일단 블럭을 정의하면, 블럭이 형성한 클래스의 어근을 맨 앞에 붙여 그 블럭이 포함하는 요소들의 클래스명을 짓기 시작하면 되는 것입니다.

블럭 요소는 클래스의 어근을 형성하고 항상 맨 앞에 위치하도록 합니다. 

일단 블럭을 정의하면, 블럭이 형성한 클래스의 어근을 맨 앞에 붙여 그 블럭이 포함하는 요소들의 클래스명을 짓기 시작하면 되는 것입니다/

![img](https://t1.daumcdn.net/cfile/tistory/235E3133568B047227)

- Arbitrary placement

블럭은 페이지에서 이동될 수 있고, 페이지나 프로젝트 사이에서도 이동이 가능하다. 독립적인 존재로서 블럭 implementation은 페이지 상에서 독자적 위치를 변경가능하고 기능과 모양을 보증한다.

예를들면, auth와 logo블럭의 위치를 서로 바꿀때 block의 CSS나 Javascript 코드를 수정하지 않고 변경 가능하다.

![Altering the block positions](https://en.bem.info/v80tUiEPgSQtyW9a7C8rxdn-5EM.png)

![Altering the block positions](https://en.bem.info/0bbhZyhaBhRzqBh5nLYQEnFpDTk.png)

- Re-use

하나의 인터페이스는 여러개의 동일한 블럭을 포함할 수 있다.

![Online store products](https://en.bem.info/VBlEdksG7XkL4DLPWe4rcYb5hGo.png)



#### Element

블럭의 외부에서 사용될 수 없는 구성 요소

예를 들면, 메뉴 item은 ment 블럭의 외부에서 사용되지 않는다. 그렇게 때문에 메뉴 itemㅇㄴ elemnet이다.

![Menu items](https://en.bem.info/cPrdQL4EZZdhPIrcYOayygPBSm4.png)



#### Modifier

block이나 element의 행동이나 외형을 결정한다.

modifier는 선택적으로 사용된다.

modifier는 HTML의 특성과 비슷하다. modifier를 이용해서 같은 블럭을 다르게 보이게할 수 있다.

예를 들면, 메뉴 블럭이 modifer에 따라 다르게 보인다.

![Add a menu to the footer](https://en.bem.info/WSU5nwZla7p44W2tdxiP371xx38.png)

modifier는 runtime 동안에 바뀔 수 있다. 예를 들면, 잘못된 입력값을 주고 sign in 버튼을 누르면 (버튼을 누르는 것이 DOM 이벤트), 에러메세지를 보여줄 수 있다.



#### BEM entity

block, elements, modifers를 BEM entity라 부른다.



#### Mix

단일 DOM node에서 다른 BEM entity들을 사용하기 위한 기술

아래와 같이 혼합할 수 있습니다.

- 행동과 다수의 entity들을 코드의 중첩없이 결합
- 이미 존재하는 UI 컴포넌트를 기반으로 한 의미 상 새로운 UI 컴포넌트를 만들 때

다른 블럭의 블럭과 요소를 포함하는 mix가 있다고 가정해보자.

link블럭을 통해 링크가 설정되어 있을 경우를 가정해보면 몇가지 방법이 있다.

- 메뉴 아이템을 위한 modifier를 만들어, item을 이용해서 link를 사용하는 방법
  - 이 방법은 code의 중복생긴다.
- mix 결합을 이용해서 generic한 link 블럭과 메뉴 블럭의 link element를 가질 수 있다. 두 개의 entity를 mix하는 것은 링크블럭의 기본 기능과 추가적인 메뉴 블럭의 CSS룰을 코드의 중복 없이 적용 가능하게 한다.

#### BEM Tree

웹페이지의 구조를 BEM entity로 나타낸 것

즉, DOM tree를 추상화 한 것

- DOM tree

```html
<header class="header">
    <img class="logo">
    <form class="search-form">
        <input class="input">
        <button class="button"></button>
    </form>
    <ul class="lang-switcher">
        <li class="lang-switcher__item">
            <a class="lang-switcher__link" href="url">en</a>
        </li>
        <li class="lang-switcher__item">
            <a class="lang-switcher__link" href="url">ru</a>
        </li>
    </ul>
</header>
```

- BEM tree

```
header
    logo
    search-form
        input
        button
    lang-switcher
        lang-switcher__item
            lang-switcher__link
        lang-switcher__item
            lang-switcher__link
```

- XML

```xml
<block:header>
    <block:logo/>
    <block:search-form>
        <block:input/>
        <block:button/>
    </block:search-form>
    <block:lang-switcher>
        <elem:item>
            <elem:link/>
        </elem:item>
        <elem:item>
            <elem:link/>
        </elem:item>
    </block:lang-switcher>
</block:header>
```

- BEMJSON

```json
{
    block: 'header',
    content : [
        { block : 'logo' },
        {
            block : 'search-form',
            content : [
                { block : 'input' },
                { block : 'button' }
            ]
        },
        {
            block : 'lang-switcher',
            content : [
                {
                    elem : 'item',
                    content : [
                        { elem : 'link' }
                    ]
                },
                {
                    elem : 'item',
                    content : [
                        { elem : 'link' }
                    ]
                }
            ]
        }
    ]
}
```



#### Block implementation

아래에 기술된 BEM entity 측면을 결정하는 다른 기술들의 집합

- behavior
- appearance
- tests
- templates
- documentation
- description of dependencies
- additional data (e.g., images).



#### Implementation technology

Block implementation에 사용되는 기술

- behavior — JavaScript, CoffeeScript
- appearance — CSS, Stylus, Sass
- templates — BEMHTML, BH, Pug, Handlebars, XSL
- documentation — Markdown, Wiki, XML.

예를 들면, 어떤 블럭이 CSS로 디자인이 정의되어 있으면, 그 블럭은 CSS 기술로 implemented 되었다고 한다. 



#### Block redefinition

다른 레벨에서 블럭에 새로운 특성을 추가함으로, 블럭 implementation을 수정하는 것



#### Redefinition level

entity의 집합 또는 부분적 implementation

![Redefinition level](https://en.bem.info/kqvCO2ZXeivuLHCbn2to5chFZrM.png)


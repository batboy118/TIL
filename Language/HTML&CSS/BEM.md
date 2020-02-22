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

BEM의 장점 : 단순하지만, 좋은 구조를 가지고있다.

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
.button {
  /*모든 button 적용됨*/
  display: inline-block;
  border-radius: 3px;
  padding: 7px 12px;
  border: 1px solid #d5d5d5;
  background-image: linear-gradient(#eee, #ddd);
  font: 700 13px/18px Helvetica, arial;
}
.button--state-success {
  color: #fff;
  background: #569e3d linear-gradient(#79d858, #569e3d) repeat-x;
  border-color: #4a993e;
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

<<<<<<< HEAD
블럭이란, 기능적으로 독립적인 요소 하나하나를 의미한다.
=======
블럭이란, 기능적으로 독립적인 페이지 상의 요소 하나하나를 의미한다.

> > > > > > > 3186c9e... HTML & CSS 학습

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
  <img class="logo" />
  <form class="search-form">
    <input class="input" />
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
  "block": "header",
  "content": [
    { "block": "logo" },
    {
      "block": "search-form",
      "content": [{ "block": "input" }, { "block": "button" }]
    },
    {
      "block": "lang-switcher",
      "content": [
        {
          "elem": "item",
          "content": [{ "elem": "link" }]
        },
        {
          "elem": "item",
          "content": [{ "elem": "link" }]
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

<<<<<<< HEAD
예를 들면, 어떤 블럭이 CSS로 디자인이 정의되어 있으면, 그 블럭은 CSS 기술로 implemented 되었다고 한다.
=======
예를 들면, 어떤 블럭이 CSS로 디자인이 정의되어 있으면, 그 블럭은 CSS 기술로 implemented 되었다고 한다.

> > > > > > > 3186c9e... HTML & CSS 학습

#### Block redefinition

다른 레벨에서 블럭에 새로운 특성을 추가함으로, 블럭 implementation을 수정하는 것

#### Redefinition level

entity의 집합 또는 부분적 implementation

![Redefinition level](https://en.bem.info/kqvCO2ZXeivuLHCbn2to5chFZrM.png)

## Quick Start

#### Block

- 기능적으로 독립된 재사용이 가능한 페이지 구성요소

- HTML에서 블럭은 class로 표현된다.

- block 이름은 블럭이 목적을 묘사한다. (상태를 묘사하지 않는다.)

  ​ ex) menu or button (not red or gib)

```html
<!-- Correct. The `error` block is semantically meaningful -->
<div class="error"></div>

<!-- Incorrect. It describes the appearance -->
<div class="red-text"></div>
```

- 블록의 재사용성이나 블록이 움직일 때 필요한 독립성을 보장하기 위해 아래 두 가지를 지켜야 함

  블록은 자신의 환경에 영향을 끼칠 수 없다. 예를 들어 블록의 positioning(top, left..)이나 margin 값과 같은 외부 기하학적 요소를 설정할 수 없다.

  또한, BEM을 사용할 때 CSS 태그나 ID 셀렉터를 사용할 수 없습니다.

- Nesting

  블럭은 서로 포함관계 일 수 있다.

<<<<<<< HEAD
여러 단계로 포함될 수 있다.
=======
여러 단계로 포함될 수 있다.

> > > > > > > 3186c9e... HTML & CSS 학습

```html
<!-- `header` block -->
<header class="header">
  <!-- Nested `logo` block -->
  <div class="logo"></div>

  <!-- Nested `search-form` block -->
  <form class="search-form"></form>
</header>
```

#### Element

- block의 구성 파트로 블럭과 따로 사용될 수 없다

- element 이름은 목적으로 기술되어야 한다.(상태를 기술하면 안된다.)

<<<<<<< HEAD
ex) text or item (not red or gib)

- # element의 풀네임의 구조는 `block-name__element-name` 이고, `__`로 구분된다. (double underscore)

  ex) text or item (not red or gib)

- element의 풀네임의 구조는 `block-name__element-name` 이고, `__`로 구분된다. (double underscore)

  > > > > > > > 3186c9e... HTML & CSS 학습

  ```html
  <!-- `search-form` block -->
  <form class="search-form">
    <!-- `input` element in the `search-form` block -->
    <input class="search-form__input" />

    <!-- `button` element in the `search-form` block -->
    <button class="search-form__button">Search</button>
  </form>
  ```

- **Nesting**

  - Elements 서로 포함 될 수 있다
  - 어떤 깊이의 네스팅 레벨이던지 가질 수 있다.
  - element는 항상 block의 한 부분이다. 혼자서 쓰일 수 없다. 이 말은 element의 이름은 계층적 구조로 될 수 없음을 의미한다. (틀린 예시 `block__elem1__elem2`)

  ```html
  <!--
      Correct. The structure of the full element name follows the pattern:
      `block-name__element-name`
  -->
  <form class="search-form">
    <div class="search-form__content">
      <input class="search-form__input" />

      <button class="search-form__button">Search</button>
    </div>
  </form>

  <!--
      Incorrect. The structure of the full element name doesn't follow the pattern:
      `block-name__element-name`
  -->
  <form class="search-form">
    <div class="search-form__content">
      <!-- Recommended: `search-form__input` or `search-form__content-input` -->
      <input class="search-form__content__input" />

      <!-- Recommended: `search-form__button` or `search-form__content-button` -->
      <button class="search-form__content__button">Search</button>
    </div>
  </form>
  ```

  - 블록 이름을 namespace로 정의합니다. 이 namespace는 element들에게 block에 의존하고 있는 것을 보장합니다. (`block__elem`)

  - 한 블록은 DOM tree에서 여러 개로 중첩된 element들을 가질 수 있습니다.

  ```html
  <div class="block">
    <div class="block__elem1">
      <div class="block__elem2">
        <div class="block__elem3"></div>
      </div>
    </div>
  </div>
  ```

  - 그러나 블럭구조는 BEM 방법에서 항상 flat한 elements의 리스트를 가진다.

  ```
  .block {}
  .block__elem1 {}
  .block__elem2 {}
  .block__elem3 {}
  ```

  - 이것은 각각의 분리된 element에 대해 코드의 변화없이 블록의 DOM 구조를 변화시키는 것을 허락한다.

  ```html
  <div class="block">
    <div class="block__elem1">
      <div class="block__elem2"></div>
    </div>

    <div class="block__elem3"></div>
  </div>
  ```

  - block의 구조는 바뀌었지만, element와 이름은 동일하게 남아 있다.

* **Membership**

  - 하나의 element는 항상 블럭의 파트이고, 블럭으로 부터 따로 사용해서는 안된다.

  ```html
  <!-- Correct. Elements are located inside the `search-form` block -->
  <!-- `search-form` block -->
  <form class="search-form">
    <!-- `input` element in the `search-form` block -->
    <input class="search-form__input" />

    <!-- `button` element in the `search-form` block -->
    <button class="search-form__button">Search</button>
  </form>

  <!--
      Incorrect. Elements are located outside of the context of
      the `search-form` block
  -->
  <!-- `search-form` block -->
  <form class="search-form"></form>

  <!-- `input` element in the `search-form` block -->
  <input class="search-form__input" />

  <!-- `button` element in the `search-form` block-->
  <button class="search-form__button">Search</button>
  ```

- **Optionality**

  - element는 선택적으로 사용하는 것으로, 모든 블럭이 element를 가지는 것은 아니다.

  ```html
  <!-- `search-form` block -->
  <div class="search-form">
    <!-- `input` block -->
    <input class="input" />

    <!-- `button` block -->
    <button class="button">Search</button>
  </div>
  ```

#### Should I create a block or an element?

- **Create a block**

  만약, 코드가 재사용되고, 다른 구성요소와 독립적이라면 블럭을 생성

- **Create an elemnet**

  만약, 코드가 블럭(부모 entity)과 따로 사용될 수 없다면 element를 생성

- 하지만 간소화한 개발을 위하여 작은 부분들로 분리되어야 하는 element들은 예외입니다. BEM 방법론에서 element 들의 element 들은 만들 수 없습니다. 이와 같은 경우, element를 만드는 것 대신에 service 블록을 만들어야 합니다.

#### Modifier

- 블럭과 element의 외형과 state, 행동을 정의하는 entity

- Modifier name은 외형이나 사애 또는 행동을 묘사함

- block\_\_element_modifier 이름을 가짐 (\_로 구분함, single underscore)

- **Types of Modifiers**

  - Boolean
    - modifier의 유무가 중요할 때 사용된다. 예를 들어, 값이 상관없으면 `disabled` , Boolean modifier가 나타난다면 그 값은 `true` 로 가정할 수 있다.
    - modifier는 아래 두 가지 이름을 가질 수 있다.
      1. `block-name_modifier-name`
      2. `block-name__element-name_modifier-name`

  ```html
  <!-- The `search-form` block has the `focused` Boolean modifier -->
  <form class="search-form search-form_focused">
    <input class="search-form__input" />

    <!-- The `button` element has the `disabled` Boolean modifier -->
    <button class="search-form__button search-form__button_disabled">
      Search
    </button>
  </form>
  ```

* Key-value
  - modifier의 값이 중요할 때 사용한다. 예를 들어, `islands` 디자인 테마와 함께 사용되는 메뉴에 `menu_theme_islands`
  - modifier는 아래 두가지 이름을 가진다.
    - `block-name_modifier-name_modifier-value`
    - `block-name__element-name_modifier-name_modifier-value`

```html
<!-- The `search-form` block has the `theme` modifier with the value `islands` -->
<form class="search-form search-form_theme_islands">
  <input class="search-form__input" />

  <!-- The `button` element has the `size` modifier with the value `m` -->
  <button class="search-form__button search-form__button_size_m">Search</button>
</form>

<!-- You can't use two identical modifiers with different values simultaneously -->
<form
  class="search-form
             search-form_theme_islands
             search-form_theme_lite"
>
  <input class="search-form__input" />

  <button
    class="search-form__button
                   search-form__button_size_s
                   search-form__button_size_m"
  >
    Search
  </button>
</form>
```

- modifier는 혼자서 쓰일 수 없다.

  ```html
  <!--
      Correct. The `search-form` block has the `theme` modifier with
      the value `islands`
  -->
  <form class="search-form search-form_theme_islands">
    <input class="search-form__input" />

    <button class="search-form__button">Search</button>
  </form>

  <!-- Incorrect. The modified class `search-form` is missing -->
  <form class="search-form_theme_islands">
    <input class="search-form__input" />

    <button class="search-form__button">Search</button>
  </form>
  ```

  [Why write the block name in the names of modifiers and elements?](https://en.bem.info/methodology/faq/#why-include-the-block-name-in-modifier-and-element-names)

#### Mix

- single DOM node에서 서로 다른 BEM entity를 사용하는 기술

- Mix를 사용하면
  - 다수의 엔티티의 행동과 스타일을 코드의 중첩없이 결합가능
  - 이미 존재하는 UI 컴포넌트를 기반으로 의미를 가진 새로운 UI 컴포넌트를 만들수 있음

```html
<!-- `header` block -->
<div class="header">
  <!--
        The `search-form` block is mixed with the `search-form` element
        from the `header` block
    -->
  <div class="search-form header__search-form"></div>
</div>
```

이 접근 방식을 통해 `search-form` 블록 자체는 보편적인 상태로 유지하면서 `header__search-form` elemnet의 외부 형상 및 위치를 설정할 수 있다.

결과적으로, 우리는 어떤 다른 환경에서도 `search-form` block을 사용할 수 있다. 왜냐하면 그것은 어떤 패딩도 명시하지 않기 때문이다. 이것이 우리가 그것을 독립적이라고 부를 수 있는 이유다.

#### File structure

- BEM 방법론에서 채택 된 컴포넌트 접근법은 또한 프로젝트의 파일구조에도 적용된다. block과 element, modifier의 구현은 독립적인 기술 파일들로 분리되며, 독립된 파일들을 각각 따로 연결할 수 있다.

- 하나의 block은 하나의 디렉토리에 상응한다.
- block과 directory는 같은 이름을 가진다. 예를 들어, `header` block은 `header/` directory안에, 있고 `menu` block은 `menu/` directory 안에 있다.
- block들의 구현체는 독립된 기술 파일들로 나뉘어진다. 예를 들어, `header.css`와 `header.js`로 구성된다.
- block directory는 block의 element들과 modifier들이 위치한 subdirectory의 root directory이다.
- element directory의 이름은 이중 underscore(`__`)로 시작한다. 예를 들어, `header/__logo` 나 `menu/__item/` 과 같다.
- modifier directory의 이름은 단일 underscore(`_`)로 시작한다. 예를 들어, `header/_fixed/` 와 `menu/_theme_islands/` 와 같다.
- element들과 modifier의 구현체는 각각 기술 파일들로 나누어진다. 예를 들어, `header__input.js`와 `header_theme_islands.css` 와 같다.

```
search-form/                           # Directory of the search-form

    __input/                           # Subdirectory of the search-form__input
        search-form__input.css         # CSS implementation of the
                                       # search-form__input element
        search-form__input.js          # JavaScript implementation of the
                                       # search-form__input element

    __button/                          # Subdirectory of the search-form__button
                                       # element
        search-form__button.css
        search-form__button.js

    _theme/                            # Subdirectory of the search-form_theme
                                       # modifier
        search-form_theme_islands.css  # CSS implementation of the search-form block
                                       # that has the theme modifier with the value
                                       # islands
        search-form_theme_lite.css     # CSS implementation of the search-form block
                                       # that has the theme modifier with the value
                                       # lite

    search-form.css                    # CSS implementation of the search-form block
    search-form.js                     # JavaScript implementation of the
                                       # search-form block
```

위와 같은 파일 구조는 코드의 재사용성을 높인다.

위의 파일 구조는 추천 사항이지 필수 사항이 아니며, 다른 대안의 프로젝트 구조를 사용 할 수 있다. 또한, 파일을 구성하기 위한 BEM 원칙을 따르기만 해도 된다.
=======
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

블럭이란, 기능적으로 독립적인 페이지 상의 요소 하나하나를 의미한다. 

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

## Quick Start

#### Block

- 기능적으로 독립된 재사용이 가능한 페이지 구성요소

- HTML에서 블럭은 class로 표현된다.

- block 이름은 블럭이 목적을 묘사한다. (상태를 묘사하지 않는다.)

  ​	ex) menu or button (not red or gib)

```html
<!-- Correct. The `error` block is semantically meaningful -->
<div class="error"></div>

<!-- Incorrect. It describes the appearance -->
<div class="red-text"></div>
```



- 블록의 재사용성이나 블록이 움직일 때 필요한 독립성을 보장하기 위해 아래 두 가지를 지켜야 함

  블록은 자신의 환경에 영향을 끼칠 수 없다. 예를 들어 블록의 positioning(top, left..)이나 margin 값과 같은 외부 기하학적 요소를 설정할 수 없다.

  또한, BEM을 사용할 때 CSS 태그나 ID 셀렉터를 사용할 수 없습니다.

- Nesting

  블럭은 서로 포함관계 일 수 있다.

  여러 단계로 포함될 수 있다. 

```html
   <!-- `header` block -->
    <header class="header">
        <!-- Nested `logo` block -->
        <div class="logo"></div>

        <!-- Nested `search-form` block -->
        <form class="search-form"></form>
    </header>
```



#### Element

- block의 구성 파트로 블럭과 따로 사용될 수 없다

- element 이름은 목적으로 기술되어야 한다.(상태를 기술하면 안된다.)

  ex)  text or item (not red or gib)

- element의 풀네임의 구조는  `block-name__element-name` 이고, `__`로 구분된다. (double underscore)

  ```html
  <!-- `search-form` block -->
  <form class="search-form">
      <!-- `input` element in the `search-form` block -->
      <input class="search-form__input">
  
      <!-- `button` element in the `search-form` block -->
      <button class="search-form__button">Search</button>
  </form>
  ```

- **Nesting**

  - Elements 서로 포함 될 수 있다
  - 어떤 깊이의 네스팅 레벨이던지 가질 수 있다.
  - element는 항상 block의 한 부분이다. 혼자서 쓰일 수 없다. 이 말은 element의 이름은 계층적 구조로 될 수 없음을 의미한다. (틀린 예시 `block__elem1__elem2`)

  ```html
  <!--
      Correct. The structure of the full element name follows the pattern:
      `block-name__element-name`
  -->
  <form class="search-form">
      <div class="search-form__content">
          <input class="search-form__input">
  
          <button class="search-form__button">Search</button>
      </div>
  </form>
  
  <!--
      Incorrect. The structure of the full element name doesn't follow the pattern:
      `block-name__element-name`
  -->
  <form class="search-form">
      <div class="search-form__content">
          <!-- Recommended: `search-form__input` or `search-form__content-input` -->
          <input class="search-form__content__input">
  
          <!-- Recommended: `search-form__button` or `search-form__content-button` -->
          <button class="search-form__content__button">Search</button>
      </div>
  </form>
  ```

  - 블록 이름을 namespace로 정의합니다. 이 namespace는 element들에게 block에 의존하고 있는 것을 보장합니다. (`block__elem`)

  - 한 블록은 DOM tree에서 여러 개로 중첩된 element들을 가질 수 있습니다.

  ```html
  <div class="block">
      <div class="block__elem1">
          <div class="block__elem2">
              <div class="block__elem3"></div>
          </div>
      </div>
  </div>
  ```

  - 그러나 블럭구조는 BEM 방법에서 항상 flat한 elements의 리스트를 가진다.

  ```
  .block {}
  .block__elem1 {}
  .block__elem2 {}
  .block__elem3 {}
  ```

  - 이것은 각각의 분리된 element에 대해 코드의 변화없이 블록의 DOM 구조를 변화시키는 것을 허락한다.

  ```html
  <div class="block">
      <div class="block__elem1">
          <div class="block__elem2"></div>
      </div>
  
      <div class="block__elem3"></div>
  </div>
  ```

  - block의 구조는 바뀌었지만, element와 이름은 동일하게 남아 있다.

  

- **Membership**

  - 하나의 element는 항상 블럭의 파트이고, 블럭으로 부터 따로 사용해서는 안된다.

  ```html
  <!-- Correct. Elements are located inside the `search-form` block -->
  <!-- `search-form` block -->
  <form class="search-form">
      <!-- `input` element in the `search-form` block -->
      <input class="search-form__input">
  
      <!-- `button` element in the `search-form` block -->
      <button class="search-form__button">Search</button>
  </form>
  
  <!--
      Incorrect. Elements are located outside of the context of
      the `search-form` block
  -->
  <!-- `search-form` block -->
  <form class="search-form">
  </form>
  
  <!-- `input` element in the `search-form` block -->
  <input class="search-form__input">
  
  <!-- `button` element in the `search-form` block-->
  <button class="search-form__button">Search</button>
  ```

  

- **Optionality**

  - element는 선택적으로 사용하는 것으로, 모든 블럭이 element를 가지는 것은 아니다.

  ```html
  <!-- `search-form` block -->
  <div class="search-form">
      <!-- `input` block -->
      <input class="input">
  
      <!-- `button` block -->
      <button class="button">Search</button>
  </div>
  ```



#### Should I create a block or an element?

- **Create a block**

  만약, 코드가 재사용되고, 다른 구성요소와 독립적이라면 블럭을 생성

- **Create an elemnet**

  만약, 코드가 블럭(부모 entity)과 따로 사용될 수 없다면 element를 생성

- 하지만 간소화한 개발을 위하여 작은 부분들로 분리되어야 하는 element들은 예외입니다. BEM 방법론에서 element 들의 element 들은 만들 수 없습니다. 이와 같은 경우, element를 만드는 것 대신에 service 블록을 만들어야 합니다.



#### Modifier

- 블럭과 element의 외형과 state, 행동을 정의하는 entity

- Modifier name은 외형이나 사애 또는 행동을 묘사함

- block__element\_modifier 이름을 가짐 (\_로 구분함, single underscore)

- **Types of Modifiers**

  - Boolean
    - modifier의 유무가 중요할 때 사용된다. 예를 들어, 값이 상관없으면 `disabled` , Boolean modifier가 나타난다면 그 값은 `true` 로 가정할 수 있다.
    - modifier는 아래 두 가지 이름을 가질 수 있다.
      1. `block-name_modifier-name`
      2. `block-name__element-name_modifier-name`

  ```html
  <!-- The `search-form` block has the `focused` Boolean modifier -->
  <form class="search-form search-form_focused">
      <input class="search-form__input">
  
      <!-- The `button` element has the `disabled` Boolean modifier -->
      <button class="search-form__button search-form__button_disabled">Search</button>
  </form>
  ```
  

  - Key-value
    - modifier의 값이 중요할 때 사용한다. 예를 들어, `islands` 디자인 테마와 함께 사용되는 메뉴에 `menu_theme_islands`
    - modifier는 아래 두가지 이름을 가진다.
      - `block-name_modifier-name_modifier-value`
      - `block-name__element-name_modifier-name_modifier-value`

  ```html
  <!-- The `search-form` block has the `theme` modifier with the value `islands` -->
  <form class="search-form search-form_theme_islands">
      <input class="search-form__input">
  
      <!-- The `button` element has the `size` modifier with the value `m` -->
      <button class="search-form__button search-form__button_size_m">Search</button>
  </form>
  
  <!-- You can't use two identical modifiers with different values simultaneously -->
  <form class="search-form
               search-form_theme_islands
               search-form_theme_lite">
  
      <input class="search-form__input">
  
      <button class="search-form__button
                     search-form__button_size_s
                     search-form__button_size_m">
          Search
      </button>
  </form>
  ```



- modifier는 혼자서 쓰일 수 없다.

  ```html
  <!--
      Correct. The `search-form` block has the `theme` modifier with
      the value `islands`
  -->
  <form class="search-form search-form_theme_islands">
      <input class="search-form__input">
  
      <button class="search-form__button">Search</button>
  </form>
  
  <!-- Incorrect. The modified class `search-form` is missing -->
  <form class="search-form_theme_islands">
      <input class="search-form__input">
  
      <button class="search-form__button">Search</button>
  </form>
  ```

  [Why write the block name in the names of modifiers and elements?](https://en.bem.info/methodology/faq/#why-include-the-block-name-in-modifier-and-element-names)



#### Mix

- single DOM node에서 서로 다른 BEM entity를 사용하는 기술

- Mix를 사용하면
  - 다수의 엔티티의 행동과 스타일을 코드의 중첩없이 결합가능
  - 이미 존재하는 UI 컴포넌트를 기반으로 의미를 가진 새로운 UI 컴포넌트를 만들수 있음

```html
<!-- `header` block -->
<div class="header">
    <!--
        The `search-form` block is mixed with the `search-form` element
        from the `header` block
    -->
    <div class="search-form header__search-form"></div>
</div>
```

이 접근 방식을 통해 `search-form` 블록 자체는 보편적인 상태로 유지하면서 `header__search-form` elemnet의 외부 형상 및 위치를 설정할 수 있다. 

결과적으로, 우리는 어떤 다른 환경에서도 `search-form` block을 사용할 수 있다. 왜냐하면 그것은 어떤 패딩도 명시하지 않기 때문이다. 이것이 우리가 그것을 독립적이라고 부를 수 있는 이유다.



#### File structure

- BEM 방법론에서 채택 된 컴포넌트 접근법은 또한 프로젝트의 파일구조에도 적용된다. block과 element, modifier의 구현은 독립적인 기술 파일들로 분리되며, 독립된 파일들을 각각 따로 연결할 수 있다.

- 하나의 block은 하나의 디렉토리에 상응한다.
- block과 directory는 같은 이름을 가진다. 예를 들어, `header` block은 `header/` directory안에, 있고 `menu` block은 `menu/` directory 안에 있다.
- block들의 구현체는 독립된 기술 파일들로 나뉘어진다. 예를 들어, `header.css`와 `header.js`로 구성된다.
- block directory는 block의 element들과 modifier들이 위치한 subdirectory의 root directory이다.
- element directory의 이름은 이중 underscore(`__`)로 시작한다. 예를 들어, `header/__logo` 나 `menu/__item/` 과 같다.
- modifier directory의 이름은 단일 underscore(`_`)로 시작한다. 예를 들어, `header/_fixed/` 와 `menu/_theme_islands/` 와 같다.
- element들과 modifier의 구현체는 각각 기술 파일들로 나누어진다. 예를 들어, `header__input.js`와 `header_theme_islands.css` 와 같다.

```
search-form/                           # Directory of the search-form

    __input/                           # Subdirectory of the search-form__input
        search-form__input.css         # CSS implementation of the
                                       # search-form__input element
        search-form__input.js          # JavaScript implementation of the
                                       # search-form__input element

    __button/                          # Subdirectory of the search-form__button
                                       # element
        search-form__button.css
        search-form__button.js

    _theme/                            # Subdirectory of the search-form_theme
                                       # modifier
        search-form_theme_islands.css  # CSS implementation of the search-form block
                                       # that has the theme modifier with the value
                                       # islands
        search-form_theme_lite.css     # CSS implementation of the search-form block
                                       # that has the theme modifier with the value
                                       # lite

    search-form.css                    # CSS implementation of the search-form block
    search-form.js                     # JavaScript implementation of the
                                       # search-form block
```

위와 같은 파일 구조는 코드의 재사용성을 높인다.

위의 파일 구조는 추천 사항이지 필수 사항이 아니며, 다른 대안의 프로젝트 구조를 사용 할 수 있다. 또한, 파일을 구성하기 위한 BEM 원칙을 따르기만 해도 된다.

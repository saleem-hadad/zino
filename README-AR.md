<h6 align="center">
    <img src="https://github.com/saleem-hadad/zino/blob/master/assets/logo.png"/>
</h6>

<p align="center">
<a href="https://travis-ci.org/saleem-hadad/zino"><img src="https://travis-ci.org/saleem-hadad/zino.svg" alt="Build Status"></a>
<a href="https://github.com/saleem-hadad/zino"><img src="https://img.shields.io/github/release/saleem-hadad/zino.svg" alt="License"></a>
<a href="https://github.com/saleem-hadad/zino"><img src="https://poser.pugx.org/laravel/framework/license.svg" alt="License"></a>

</p>

<h1 align="right"> ♥️ 𝓩ino </h1>


<p align="right">مكتبة خاصة للتعامل مع العديد من القطع الالكترونية الشهيرة بسهولة وسرعة باستخدام متحكم أتميغا المعروف باسم أردوينو والتي يمكن استخدامها في العديد من مشاريع الأنظمة المدمجة  
</p>

<h2 align="right"> لمحة سريعة </h2>

<img align="right" src="https://github.com/saleem-hadad/zino/blob/master/assets/Pin.png" alt="Zino Pin class"/>

<p align="right">
    تقدم المكتبة مفهوم جديد للتعامل مع مخرجات ومدخلات المتحكم اضافة إلى الطريقة المستخدمة في مكتبة الأردوينو حيث يتم اعتبار كل مدخل أو مخرج كعنصر يتم ترميزه برقم واسم البورت الخاص به, فمثلاً المخرج رقم ٨ في لوحة الاردوينو يمكن ترميزه كمخرج رقمه 0 على البورت ب والسبب الرئيس في تقديم هذا المفهوم الجديد لتعريف الطلاب بمفهوم الريجسترات. لكن ان كنت تفضل استخدام الأسلوب القديم في مكتبة الأردوينو فيمكنك ذلك 😇
</p>

```c
#include <Pin.h>

Pin redLedPin(PortB, 0);            // portName: PortB, pinNumber: 0 // same as digital pin 8
Pin redLedPin(8);                   // still you can do that if you prefer :D
Pin greenLedPin(PortD, 1);          // portName: PortD, pinNumber: 1 // same as digital pin 1
Pin temperatureSensorPin(PortC, 4); // portName: PortC, pinNumber: 4 // same as analog pin A4
```

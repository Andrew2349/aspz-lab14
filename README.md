# aspz-lab14
ТВ-31 Троцюк Андрій

17 варіант

# Приклад 1: POSIX-таймер (timer_create + SIGRTMIN)

Показати, як створити повторюваний POSIX-таймер, який щосекунди викликає обробник сигналу SIGRTMIN

Код:

![image](https://github.com/user-attachments/assets/26668f16-5e24-474d-b779-cee3d5a3b7f4)

Результат:

![image](https://github.com/user-attachments/assets/c404fde7-3622-4ea6-bca0-fc3ea04bff20)

Цей приклад показує, як створити POSIX-таймер за допомогою timer_create(), який кожну секунду надсилає сигнал SIGRTMIN. Обробник сигналу виводить "Tick". Таймер точний, підтримує наносекунди та дозволяє мати кілька таймерів одночасно. Це сучасна альтернатива alarm() і setitimer() з кращою гнучкістю та підтримкою асинхронності.

# Приклад 2: alarm() + SIGALRM
Використати alarm() для генерації сигналу через 2 секунди.

Код:

![image](https://github.com/user-attachments/assets/15a2d935-c695-4165-b249-f1f7febd2720)


Результат:

![image](https://github.com/user-attachments/assets/2ac9b836-8bbb-48f9-9f8e-64c04d728326)

Цей приклад демонструє використання alarm(). Через 2 секунди генерується сигнал SIGALRM, і викликається обробник. Простий, але обмежений: лише один таймер на процес.

# Приклад 3: sleep() - затримка
Призупинити виконання програми на 3 секунди.

Код:

![image](https://github.com/user-attachments/assets/c0c03472-937c-4aae-9647-e756c37f0ce3)


Результат:

![image](https://github.com/user-attachments/assets/b1043ddc-373c-4abe-8046-4ce706057c56)

sleep() просто блокує виконання на вказаний час. Не дозволяє обробляти інші події під час сну. Не підходить для асинхронної логіки.

# Приклад 4: setitimer() + SIGALRM

Створити таймер, що викликає сигнал кожну секунду.

Код:

![image](https://github.com/user-attachments/assets/2c5ba03f-2df6-41d4-a911-51c0667dcc3f)

Результат:

![image](https://github.com/user-attachments/assets/7dd0fe0d-50e6-4adf-b761-c8400eaa7dba)

setitimer() дозволяє створити інтервальний таймер, який генерує SIGALRM. Працює краще, ніж alarm(), підтримує інтервали. Але — теж базується на сигналах, і максимум 3 таймери на процес (реальний, віртуальний, проф).

# Приклад 5: clock_nanosleep() - точна пауза

Код:

![image](https://github.com/user-attachments/assets/3ca15d4b-1963-4528-9f58-05b9e2746982)

Результат:

![image](https://github.com/user-attachments/assets/d6cc3928-2a03-45bf-9b8e-1a2cf5f6aac8)

clock_nanosleep() дозволяє зробити точну паузу до наносекунд, не генерує сигнали. Підходить для синхронних циклів (наприклад, ігор або таймерів із чіткою частотою). Але не дозволяє асинхронні обробки подій.

# Завдання 17(індивідуальне за варіантом)

Вивчіть, як зміна системного часу (через date або ntp) впливає на CLOCK_REALTIME та CLOCK_MONOTONIC таймери.

Код:

![image](https://github.com/user-attachments/assets/b1f52851-2709-4b68-945d-245c1151ee71)

Результат:

![image](https://github.com/user-attachments/assets/01880787-0564-44b5-b7ed-3dafc95ccbcd)

![image](https://github.com/user-attachments/assets/a7ac5f91-57bb-4e6b-89bf-7096c3aaee2a)

Я написав програму, яка виводить час за двома таймерами: CLOCK_REALTIME і CLOCK_MONOTONIC. Поки програма працювала, я змінював системний час командою date -s.
Очікував, що час за CLOCK_REALTIME одразу стрибне, а CLOCK_MONOTONIC буде рахувати час рівномірно без змін.
Але в результатах скачка не було. Це тому, що я запускав Ubuntu у Windows через WSL. У WSL системний час насправді керує Windows, а зміна часу в Ubuntu через date -s не змінює реальний час системи, тому таймер CLOCK_REALTIME не показує скачків.
Щоб побачити реальний вплив зміни часу на таймери, треба запускати програму в справжньому Linux - на фізичному комп’ютері або у повній віртуальній машині.

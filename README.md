Документация системы управления отелем "Hotel California"

Система управления отелем "Hotel California" предоставляет функциональность для управления номерами и гостями в отеле. Она включает в себя классы для различных типов номеров, таблицу для хранения номеров, а также классы для управления заполняемостью отеля и регистрацией гостей.
Содержание

    Класс Room
    Класс LuxuryRoom
    Класс SingleRoom
    Класс MultiRoom
    Класс OrderedTable
    Класс HotelOccupancy
    Класс HotelManagement

Класс Room

Класс Room представляет собой абстрактный базовый класс для различных типов номеров в отеле. Он определяет интерфейс для работы с номерами, включая методы для отображения информации, получения типа номера, проверки занятости, получения номера комнаты, количества гостей, занятия и освобождения номера, а также операторы сравнения.
Члены класса
Публичные члены

    virtual ~Room() = default: Виртуальный деструктор.
    virtual void displayInfo() const = 0: Чисто виртуальный метод для отображения информации о номере.
    virtual RoomType getType() const = 0: Чисто виртуальный метод для получения типа номера.
    virtual bool isOccupied() const = 0: Чисто виртуальный метод для проверки занятости номера.
    virtual int getRoomNumber() const = 0: Чисто виртуальный метод для получения номера комнаты.
    virtual int getGuestCount() const = 0: Чисто виртуальный метод для получения количества гостей в номере.
    virtual void occupyRoom(const std::string& registrationDate, int days) = 0: Чисто виртуальный метод для занятия номера.
    virtual void vacateRoom() = 0: Чисто виртуальный метод для освобождения номера.
    virtual void setName(std::string new_name) = 0: Чисто виртуальный метод для установки нового имени гостя.
    virtual bool operator==(const Room& other) const = 0: Чисто виртуальный оператор равенства для сравнения номеров.
    virtual bool operator<(const Room& other) const = 0: Чисто виртуальный оператор меньше для сравнения номеров.
    virtual bool operator>(const Room& other) const = 0: Чисто виртуальный оператор больше для сравнения номеров.

Подробная документация методов
virtual ~Room() = default

Описание: Виртуальный деструктор.

Параметры: Нет

Возвращает: Нет
virtual void displayInfo() const = 0

Описание: Чисто виртуальный метод для отображения информации о номере.

Параметры: Нет

Возвращает: Нет
virtual RoomType getType() const = 0

Описание: Чисто виртуальный метод для получения типа номера.

Параметры: Нет

Возвращает:

    RoomType: Тип номера.

virtual bool isOccupied() const = 0

Описание: Чисто виртуальный метод для проверки занятости номера.

Параметры: Нет

Возвращает:

    bool: true, если номер занят, иначе false.

virtual int getRoomNumber() const = 0

Описание: Чисто виртуальный метод для получения номера комнаты.

Параметры: Нет

Возвращает:

    int: Номер комнаты.

virtual int getGuestCount() const = 0

Описание: Чисто виртуальный метод для получения количества гостей в номере.

Параметры: Нет

Возвращает:

    int: Количество гостей в номере.

virtual void occupyRoom(const std::string& registrationDate, int days) = 0

Описание: Чисто виртуальный метод для занятия номера.

Параметры:

    const std::string& registrationDate: Дата регистрации гостя.
    int days: Количество дней, на которое забронирован номер.

Возвращает: Нет
virtual void vacateRoom() = 0

Описание: Чисто виртуальный метод для освобождения номера.

Параметры: Нет

Возвращает: Нет
virtual void setName(std::string new_name) = 0

Описание: Чисто виртуальный метод для установки нового имени гостя.

Параметры:

    std::string new_name: Новое имя гостя.

Возвращает: Нет
virtual bool operator==(const Room& other) const = 0

Описание: Чисто виртуальный оператор равенства для сравнения номеров.

Параметры:

    const Room& other: Другой номер для сравнения.

Возвращает:

    bool: true, если номера равны, иначе false.

virtual bool operator<(const Room& other) const = 0

Описание: Чисто виртуальный оператор меньше для сравнения номеров.

Параметры:

    const Room& other: Другой номер для сравнения.

Возвращает:

    bool: true, если текущий номер меньше другого номера, иначе false.

virtual bool operator>(const Room& other) const = 0

Описание: Чисто виртуальный оператор больше для сравнения номеров.

Параметры:

    const Room& other: Другой номер для сравнения.

Возвращает:

    bool: true, если текущий номер больше другого номера, иначе false.

Перечисление RoomType

Перечисление RoomType определяет типы номеров в отеле.
Члены перечисления

    LUXURY: Тип номера "люкс".
    SINGLE: Тип номера "одноместный".
    MULTI: Тип номера "многоместный".

Класс LuxuryRoom

Класс LuxuryRoom представляет собой тип номера "люкс" в отеле. Он наследует базовый класс Room и переопределяет его методы для работы с номерами типа "люкс".
Члены класса
Публичные члены

    LuxuryRoom(int roomNumber, bool occupied, int numRooms, int numGuests, const std::string& registrationDate, int days, double dailyRate): Конструктор для инициализации объекта LuxuryRoom.
    void displayInfo() const override: Выводит информацию о номере.
    RoomType getType() const override: Возвращает тип номера.
    bool isOccupied() const override: Проверяет, занят ли номер.
    int getGuestCount() const override: Возвращает количество гостей в номере.
    void occupyRoom(const std::string& registrationDate, int days) override: Занимает номер.
    const std::string& getGuestName() const: Возвращает имя гостя.
    void setName(std::string new_name): Устанавливает новое имя гостя.
    void vacateRoom() override: Освобождает номер.
    bool operator==(const Room& other) const override: Оператор равенства для сравнения номеров.
    int getRoomNumber() const: Возвращает номер комнаты.
    bool operator<(const Room& other) const override: Оператор меньше для сравнения номеров.
    bool operator>(const Room& other) const override: Оператор больше для сравнения номеров.

Приватные члены

    int roomNumber: Номер комнаты.
    bool occupied: Флаг, указывающий, занят ли номер.
    int numRooms: Количество комнат в номере.
    int numGuests: Количество гостей в номере.
    std::string registrationDate: Дата регистрации гостя.
    std::string name: Имя гостя.
    int days: Количество дней, на которое забронирован номер.
    double dailyRate: Дневная ставка за номер.

Подробная документация методов
LuxuryRoom(int roomNumber, bool occupied, int numRooms, int numGuests, const std::string& registrationDate, int days, double dailyRate)

Описание: Конструктор для инициализации объекта LuxuryRoom.

Параметры:

    int roomNumber: Номер комнаты.
    bool occupied: Флаг, указывающий, занят ли номер.
    int numRooms: Количество комнат в номере.
    int numGuests: Количество гостей в номере.
    const std::string& registrationDate: Дата регистрации гостя.
    int days: Количество дней, на которое забронирован номер.
    double dailyRate: Дневная ставка за номер.

Возвращает: Нет
void displayInfo() const override

Описание: Выводит информацию о номере.

Параметры: Нет

Возвращает: Нет
RoomType getType() const override

Описание: Возвращает тип номера.

Параметры: Нет

Возвращает:

    RoomType: Тип номера.

bool isOccupied() const override

Описание: Проверяет, занят ли номер.

Параметры: Нет

Возвращает:

    bool: true, если номер занят, иначе false.

int getGuestCount() const override

Описание: Возвращает количество гостей в номере.

Параметры: Нет

Возвращает:

    int: Количество гостей в номере.

void occupyRoom(const std::string& registrationDate, int days) override

Описание: Занимает номер.

Параметры:

    const std::string& registrationDate: Дата регистрации гостя.
    int days: Количество дней, на которое забронирован номер.

Возвращает: Нет
const std::string& getGuestName() const

Описание: Возвращает имя гостя.

Параметры: Нет

Возвращает:

    const std::string&: Имя гостя.

void setName(std::string new_name)

Описание: Устанавливает новое имя гостя.

Параметры:

    std::string new_name: Новое имя гостя.

Возвращает: Нет
void vacateRoom() override

Описание: Освобождает номер.

Параметры: Нет

Возвращает: Нет
bool operator==(const Room& other) const override

Описание: Оператор равенства для сравнения номеров.

Параметры:

    const Room& other: Другой номер для сравнения.

Возвращает:

    bool: true, если номера равны, иначе false.

int getRoomNumber() const

Описание: Возвращает номер комнаты.

Параметры: Нет

Возвращает:

    int: Номер комнаты.

bool operator<(const Room& other) const override

Описание: Оператор меньше для сравнения номеров.

Параметры:

    const Room& other: Другой номер для сравнения.

Возвращает:

    bool: true, если текущий номер меньше другого номера, иначе false.

bool operator>(const Room& other) const override

Описание: Оператор больше для сравнения номеров.

Параметры:

    const Room& other: Другой номер для сравнения.

Возвращает:

    bool: true, если текущий номер больше другого номера, иначе false.

Класс SingleRoom

Класс SingleRoom представляет собой тип номера "одноместный" в отеле. Он наследует базовый класс Room и переопределяет его методы для работы с номерами типа "одноместный".
Члены класса
Публичные члены

    SingleRoom(int roomNumber, bool occupied, const std::string& registrationDate, int days, double dailyRate): Конструктор для инициализации объекта SingleRoom.
    void displayInfo() const override: Выводит информацию о номере.
    RoomType getType() const override: Возвращает тип номера.
    bool isOccupied() const override: Проверяет, занят ли номер.
    int getGuestCount() const override: Возвращает количество гостей в номере.
    void setName(std::string new_name): Устанавливает новое имя гостя.
    const std::string& getGuestName() const: Возвращает имя гостя.
    void occupyRoom(const std::string& registrationDate, int days) override: Занимает номер.
    void vacateRoom() override: Освобождает номер.
    bool operator==(const Room& other) const override: Оператор равенства для сравнения номеров.
    int getRoomNumber() const: Возвращает номер комнаты.
    bool operator<(const Room& other) const override: Оператор меньше для сравнения номеров.
    bool operator>(const Room& other) const override: Оператор больше для сравнения номеров.

Приватные члены

    int roomNumber: Номер комнаты.
    bool occupied: Флаг, указывающий, занят ли номер.
    std::string registrationDate: Дата регистрации гостя.
    int days: Количество дней, на которое забронирован номер.
    std::string name: Имя гостя.
    double dailyRate: Дневная ставка за номер.

Подробная документация методов
SingleRoom(int roomNumber, bool occupied, const std::string& registrationDate, int days, double dailyRate)

Описание: Конструктор для инициализации объекта SingleRoom.

Параметры:

    int roomNumber: Номер комнаты.
    bool occupied: Флаг, указывающий, занят ли номер.
    const std::string& registrationDate: Дата регистрации гостя.
    int days: Количество дней, на которое забронирован номер.
    double dailyRate: Дневная ставка за номер.

Возвращает: Нет
void displayInfo() const override

Описание: Выводит информацию о номере.

Параметры: Нет

Возвращает: Нет
RoomType getType() const override

Описание: Возвращает тип номера.

Параметры: Нет

Возвращает:

    RoomType: Тип номера.

bool isOccupied() const override

Описание: Проверяет, занят ли номер.

Параметры: Нет

Возвращает:

    bool: true, если номер занят, иначе false.

int getGuestCount() const override

Описание: Возвращает количество гостей в номере.

Параметры: Нет

Возвращает:

    int: Количество гостей в номере.

void setName(std::string new_name)

Описание: Устанавливает новое имя гостя.

Параметры:

    std::string new_name: Новое имя гостя.

Возвращает: Нет
const std::string& getGuestName() const

Описание: Возвращает имя гостя.

Параметры: Нет

Возвращает:

    const std::string&: Имя гостя.

void occupyRoom(const std::string& registrationDate, int days) override

Описание: Занимает номер.

Параметры:

    const std::string& registrationDate: Дата регистрации гостя.
    int days: Количество дней, на которое забронирован номер.

Возвращает: Нет
void vacateRoom() override

Описание: Освобождает номер.

Параметры: Нет

Возвращает: Нет
bool operator==(const Room& other) const override

Описание: Оператор равенства для сравнения номеров.

Параметры:

    const Room& other: Другой номер для сравнения.

Возвращает:

    bool: true, если номера равны, иначе false.

int getRoomNumber() const

Описание: Возвращает номер комнаты.

Параметры: Нет

Возвращает:

    int: Номер комнаты.

bool operator<(const Room& other) const override

Описание: Оператор меньше для сравнения номеров.

Параметры:

    const Room& other: Другой номер для сравнения.

Возвращает:

    bool: true, если текущий номер меньше другого номера, иначе false.

bool operator>(const Room& other) const override

Описание: Оператор больше для сравнения номеров.

Параметры:

    const Room& other: Другой номер для сравнения.

Возвращает:

    bool: true, если текущий номер больше другого номера, иначе false.

Класс MultiRoom

Класс MultiRoom представляет собой тип номера "многоместный" в отеле. Он наследует базовый класс Room и переопределяет его методы для работы с номерами типа "многоместный".
Члены класса
Публичные члены

    MultiRoom(int roomNumber, bool isOccupied, int maxGuests, int guestCount, const std::vectorstd::string& guests, double price): Конструктор для инициализации объекта MultiRoom.
    RoomType getType() const override: Возвращает тип номера.
    bool isOccupied() const override: Проверяет, занят ли номер.
    void displayInfo() const override: Выводит информацию о номере.
    int getGuestCount() const override: Возвращает количество гостей в номере.
    void occupyRoom(const std::string& registrationDate, int days) override: Занимает номер.
    void vacateRoom() override: Освобождает номер.
    void occupyPart(const std::string& registrationDate, int days): Занимает часть номера.
    bool isFull() const: Проверяет, заполнен ли номер.
    bool isEmpty() const: Проверяет, пуст ли номер.
    const std::vectorstd::string& getGuests() const: Возвращает список гостей.
    void setName(std::string new_name): Устанавливает новое имя гостя.
    void vacatePart(): Освобождает часть номера.
    bool addGuest(const std::string& guestName): Добавляет гостя в номер.
    bool removeGuest(const std::string& guestName): Удаляет гостя из номера.
    void setGuestCount(int count): Устанавливает количество гостей в номере.
    int getMaxGuests(): Возвращает максимальное количество гостей в номере.
    void clearGuests(): Очищает список гостей.
    bool operator==(const Room& other) const override: Оператор равенства для сравнения номеров.
    bool operator<(const Room& other) const override: Оператор меньше для сравнения номеров.
    int getRoomNumber() const: Возвращает номер комнаты.
    bool operator>(const Room& other) const override: Оператор больше для сравнения номеров.

Приватные члены

    int roomNumber: Номер комнаты.
    bool occupied: Флаг, указывающий, занят ли номер.
    int totalSpaces: Общее количество мест в номере.
    int occupiedSpaces: Количество занятых мест в номере.
    std::vector<std::pair<std::string, int>> guestInfo: Информация о гостях (имя и количество дней).
    double dailyRate: Дневная ставка за номер.
    std::vectorstd::string guests: Список имен гостей.
    int maxGuests: Максимальное количество гостей в номере.
    std::string name: Имя гостя.

Подробная документация методов
MultiRoom(int roomNumber, bool isOccupied, int maxGuests, int guestCount, const std::vectorstd::string& guests, double price)

Описание: Конструктор для инициализации объекта MultiRoom.

Параметры:

    int roomNumber: Номер комнаты.
    bool isOccupied: Флаг, указывающий, занят ли номер.
    int maxGuests: Максимальное количество гостей в номере.
    int guestCount: Текущее количество гостей в номере.
    const std::vector<std::string>& guests: Список имен гостей.
    double price: Дневная ставка за номер.

Возвращает: Нет
RoomType getType() const override

Описание: Возвращает тип номера.

Параметры: Нет

Возвращает:

    RoomType: Тип номера.

bool isOccupied() const override

Описание: Проверяет, занят ли номер.

Параметры: Нет

Возвращает:

    bool: true, если номер занят, иначе false.

void displayInfo() const override

Описание: Выводит информацию о номере.

Параметры: Нет

Возвращает: Нет
int getGuestCount() const override

Описание: Возвращает количество гостей в номере.

Параметры: Нет

Возвращает:

    int: Количество гостей в номере.

void occupyRoom(const std::string& registrationDate, int days) override

Описание: Занимает номер.

Параметры:

    const std::string& registrationDate: Дата регистрации гостя.
    int days: Количество дней, на которое забронирован номер.

Возвращает: Нет
void vacateRoom() override

Описание: Освобождает номер.

Параметры: Нет

Возвращает: Нет
void occupyPart(const std::string& registrationDate, int days)

Описание: Занимает часть номера.

Параметры:

    const std::string& registrationDate: Дата регистрации гостя.
    int days: Количество дней, на которое забронирована часть номера.

Возвращает: Нет
bool isFull() const

Описание: Проверяет, заполнен ли номер.

Параметры: Нет

Возвращает:

    bool: true, если номер заполнен, иначе false.

bool isEmpty() const

Описание: Проверяет, пуст ли номер.

Параметры: Нет

Возвращает:

    bool: true, если номер пуст, иначе false.

const std::vectorstd::string& getGuests() const

Описание: Возвращает список гостей.

Параметры: Нет

Возвращает:

    const std::vector<std::string>&: Список гостей.

void setName(std::string new_name)

Описание: Устанавливает новое имя гостя.

Параметры:

    std::string new_name: Новое имя гостя.

Возвращает: Нет
void vacatePart()

Описание: Освобождает часть номера.

Параметры: Нет

Возвращает: Нет
bool addGuest(const std::string& guestName)

Описание: Добавляет гостя в номер.

Параметры:

    const std::string& guestName: Имя гостя.

Возвращает:

    bool: true, если гость успешно добавлен, иначе false.

bool removeGuest(const std::string& guestName)

Описание: Удаляет гостя из номера.

Параметры:

    const std::string& guestName: Имя гостя.

Возвращает:

    bool: true, если гость успешно удален, иначе false.

void setGuestCount(int count)

Описание: Устанавливает количество гостей в номере.

Параметры:

    int count: Количество гостей.

Возвращает: Нет
int getMaxGuests()

Описание: Возвращает максимальное количество гостей в номере.

Параметры: Нет

Возвращает:

    int: Максимальное количество гостей в номере.

void clearGuests()

Описание: Очищает список гостей.

Параметры: Нет

Возвращает: Нет
bool operator==(const Room& other) const override

Описание: Оператор равенства для сравнения номеров.

Параметры:

    const Room& other: Другой номер для сравнения.

Возвращает:

    bool: true, если номера равны, иначе false.

bool operator<(const Room& other) const override

Описание: Оператор меньше для сравнения номеров.

Параметры:

    const Room& other: Другой номер для сравнения.

Возвращает:

    bool: true, если текущий номер меньше другого номера, иначе false.

int getRoomNumber() const

Описание: Возвращает номер комнаты.

Параметры: Нет

Возвращает:

    int: Номер комнаты.

bool operator>(const Room& other) const override

Описание: Оператор больше для сравнения номеров.

Параметры:

    const Room& other: Другой номер для сравнения.

Возвращает:

    bool: true, если текущий номер больше другого номера, иначе false.

Класс OrderedTable

Класс OrderedTable представляет собой шаблонный контейнер для хранения упорядоченных данных. Он поддерживает вставку, поиск, удаление элементов, а также предоставляет итераторы для обхода элементов. Класс использует мьютекс для обеспечения потокобезопасности.
Члены класса
Приватные члены

    T data: Массив указателей на элементы типа T.
    size_t capacity: Емкость массива.
    size_t size: Текущий размер массива (количество элементов).
    std::mutex mtx: Мьютекс для обеспечения потокобезопасности.

Приватные методы

    void resize(size_t new_capacity): Изменяет емкость массива.

Публичные члены

    OrderedTable(size_t initial_capacity = 10): Конструктор для инициализации объекта OrderedTable с начальной емкостью.
    ~OrderedTable(): Деструктор для освобождения памяти.
    *void insert(T value)**: Вставляет элемент в массив, сохраняя порядок.
    bool search(const T& value) const: Ищет элемент в массиве.
    *bool remove(T value)**: Удаляет элемент из массива.
    void print() const: Выводит элементы массива на экран.
    Iterator begin(): Возвращает итератор на начало массива.
    Iterator end(): Возвращает итератор на конец массива.
    const Iterator begin() const: Возвращает константный итератор на начало массива.
    const Iterator end() const: Возвращает константный итератор на конец массива.
    size_t getSize() const: Возвращает текущий размер массива.

Подробная документация методов
OrderedTable(size_t initial_capacity = 10)

Описание: Конструктор для инициализации объекта OrderedTable с начальной емкостью.

Параметры:

    size_t initial_capacity: Начальная емкость массива (по умолчанию 10).

Возвращает: Нет
~OrderedTable()

Описание: Деструктор для освобождения памяти.

Параметры: Нет

Возвращает: Нет
void insert(T* value)

Описание: Вставляет элемент в массив, сохраняя порядок.

Параметры:

    T* value: Указатель на элемент, который нужно вставить.

Возвращает: Нет
bool search(const T& value) const

Описание: Ищет элемент в массиве.

Параметры:

    const T& value: Элемент, который нужно найти.

Возвращает:

    bool: true, если элемент найден, иначе false.

bool remove(T* value)

Описание: Удаляет элемент из массива.

Параметры:

    T* value: Указатель на элемент, который нужно удалить.

Возвращает:

    bool: true, если элемент удален, иначе false.

void print() const

Описание: Выводит элементы массива на экран.

Параметры: Нет

Возвращает: Нет
Iterator begin()

Описание: Возвращает итератор на начало массива.

Параметры: Нет

Возвращает:

    Iterator: Итератор на начало массива.

Iterator end()

Описание: Возвращает итератор на конец массива.

Параметры: Нет

Возвращает:

    Iterator: Итератор на конец массива.

const Iterator begin() const

Описание: Возвращает константный итератор на начало массива.

Параметры: Нет

Возвращает:

    const Iterator: Константный итератор на начало массива.

const Iterator end() const

Описание: Возвращает константный итератор на конец массива.

Параметры: Нет

Возвращает:

    const Iterator: Константный итератор на конец массива.

size_t getSize() const

Описание: Возвращает текущий размер массива.

Параметры: Нет

Возвращает:

    size_t: Текущий размер массива.

Класс Iterator

Класс Iterator предоставляет итератор для обхода элементов массива.
Публичные члены

    using iterator_category = std::bidirectional_iterator_tag: Категория итератора.
    using difference_type = std::ptrdiff_t: Тип разницы.
    using value_type = T: Тип значения.
    *using pointer = T`: Тип указателя.
    using reference = T&: Тип ссылки.

Конструктор

    *Iterator(pointer ptr)**: Конструктор для инициализации итератора.

Операторы

    reference operator() const*: Оператор разыменования.
    pointer operator->(): Оператор доступа к члену.
    Iterator& operator++(): Префиксный оператор инкремента.
    Iterator operator++(int): Постфиксный оператор инкремента.
    Iterator& operator--(): Префиксный оператор декремента.
    Iterator operator--(int): Постфиксный оператор декремента.
    friend bool operator==(const Iterator& a, const Iterator& b): Оператор равенства.
    friend bool operator!=(const Iterator& a, const Iterator& b): Оператор неравенства.

Приватные члены

    pointer current*: Текущий указатель на элемент.

Класс HotelOccupancy

Класс HotelOccupancy предназначен для расчета коэффициента заполняемости отеля на основе информации о номерах. Он использует многопоточность для ускорения вычислений и мьютекс для обеспечения потокобезопасности.
Члены класса
Приватные члены

    const OrderedTable<Room>& rooms: Константная ссылка на таблицу номеров.
    mutable std::mutex mtx: Мьютекс для обеспечения потокобезопасности.

Публичные члены

    HotelOccupancy(const OrderedTable<Room>& rooms): Конструктор для инициализации объекта HotelOccupancy.
    double calculateOccupancy() const: Рассчитывает коэффициент заполняемости отеля.

Подробная документация методов
HotelOccupancy(const OrderedTable<Room>& rooms)

Описание: Конструктор для инициализации объекта HotelOccupancy.

Параметры:

    const OrderedTable<Room>& rooms: Константная ссылка на таблицу номеров.

Возвращает: Нет
double calculateOccupancy() const

Описание: Рассчитывает коэффициент заполняемости отеля.

Параметры: Нет

Возвращает:

    double: Коэффициент заполняемости отеля.

Реализация метода calculateOccupancy

Метод calculateOccupancy использует многопоточность для расчета коэффициента заполняемости. Он создает несколько потоков, каждый из которых обрабатывает определенный тип номеров (люкс, одноместные, многоместные). Результаты обработки каждого потока сохраняются в векторе results, который затем используется для вычисления общего коэффициента заполняемости.
Приватные методы и лямбда-функции

    processRooms: Лямбда-функция, которая обрабатывает номера определенного типа в заданном диапазоне.

Локальные переменные

    int totalSpaces: Общее количество мест в отеле.
    int occupiedSpaces: Количество занятых мест в отеле.
    std::vectorstd::thread threads: Вектор потоков для многопоточной обработки.
    std::vector<int> results: Вектор для хранения результатов обработки каждого потока.

Лямбда-функция processRooms

Описание: Лямбда-функция, которая обрабатывает номера определенного типа в заданном диапазоне.

Параметры:

    int start: Начальный индекс диапазона.
    int end: Конечный индекс диапазона.
    int index: Индекс для сохранения результатов в векторе results.
    RoomType roomType: Тип номера для обработки.

Локальные переменные:

    int localTotalSpaces: Локальное количество мест для текущего потока.
    int localOccupiedSpaces: Локальное количество занятых мест для текущего потока.
    auto it: Итератор для обхода номеров.

Реализация:

    Инициализирует локальные переменные localTotalSpaces и localOccupiedSpaces.
    Обходит номера в заданном диапазоне и подсчитывает количество мест и занятых мест для указанного типа номера.
    Сохраняет результаты в векторе results с использованием мьютекса для обеспечения потокобезопасности.

Основной алгоритм

    Инициализирует переменные totalSpaces и occupiedSpaces.
    Создает вектор потоков threads и вектор результатов results.
    Запускает потоки для обработки каждого типа номеров.
    Ждет завершения всех потоков.
    Суммирует результаты из вектора results для вычисления общего количества мест и занятых мест.
    Возвращает коэффициент заполняемости как отношение занятых мест к общему количеству мест.

Класс HotelManagement

Класс HotelManagement предназначен для управления номерами и гостями в отеле. Он предоставляет функциональность для добавления номеров, регистрации гостей, удаления гостей, выписки гостей, перечисления доступных и занятых номеров, а также для расчета коэффициента заполняемости.
Члены класса
Приватные члены

    OrderedTable<Room> rooms: Таблица для хранения номеров в отеле.
    std::unordered_map<RoomType, std::string> roomTypeMap: Карта для хранения типов номеров и их соответствующих строковых представлений.

Публичные члены

    HotelManagement(): Конструктор для инициализации объекта HotelManagement.
    *void addRoom(Room room)**: Добавляет номер в отель.
    void registerGuest(const std::string& guestName, int roomNumber, const std::string& registrationDate, int days): Регистрирует гостя с указанным номером комнаты, датой регистрации и количеством дней.
    void registerGuest(const std::string& guestName, int roomNumber): Регистрирует гостя с указанным номером комнаты.
    void removeGuest(const std::string& guestName, int roomNumber): Удаляет гостя из указанного номера.
    void checkoutGuest(int roomNumber): Выписывает гостя из указанного номера.
    void listAvailableRooms() const: Перечисляет все доступные номера в отеле.
    void listMultiRooms() const: Перечисляет все многоместные номера в отеле.
    void listFullRooms() const: Перечисляет все занятые номера в отеле.
    double calculateOccupancy() const: Рассчитывает коэффициент заполняемости отеля.
    const OrderedTable<Room>& getRooms() const: Возвращает константную ссылку на таблицу номеров.
    OrderedTable<Room>::Iterator getRoomsBegin() const: Возвращает итератор на начало таблицы номеров.
    OrderedTable<Room>::Iterator getRoomsEnd() const: Возвращает итератор на конец таблицы номеров.

Подробная документация методов
HotelManagement()

Описание: Конструктор для инициализации объекта HotelManagement.

Параметры: Нет

Возвращает: Нет
void addRoom(Room* room)

Описание: Добавляет номер в отель.

Параметры:

    Room* room: Указатель на номер, который нужно добавить.

Возвращает: Нет
void registerGuest(const std::string& guestName, int roomNumber, const std::string& registrationDate, int days)

Описание: Регистрирует гостя с указанным номером комнаты, датой регистрации и количеством дней.

Параметры:

    const std::string& guestName: Имя гостя.
    int roomNumber: Номер комнаты для регистрации гостя.
    const std::string& registrationDate: Дата регистрации гостя.
    int days: Количество дней, которые гость будет проживать.

Возвращает: Нет
void registerGuest(const std::string& guestName, int roomNumber)

Описание: Регистрирует гостя с указанным номером комнаты.

Параметры:

    const std::string& guestName: Имя гостя.
    int roomNumber: Номер комнаты для регистрации гостя.

Возвращает: Нет
void removeGuest(const std::string& guestName, int roomNumber)

Описание: Удаляет гостя из указанного номера.

Параметры:

    const std::string& guestName: Имя гостя, которого нужно удалить.
    int roomNumber: Номер комнаты, из которой будет удален гость.

Возвращает: Нет
void checkoutGuest(int roomNumber)

Описание: Выписывает гостя из указанного номера.

Параметры:

    int roomNumber: Номер комнаты, из которой будет выписан гость.

Возвращает: Нет
void listAvailableRooms() const

Описание: Перечисляет все доступные номера в отеле.

Параметры: Нет

Возвращает: Нет
void listMultiRooms() const

Описание: Перечисляет все многоместные номера в отеле.

Параметры: Нет

Возвращает: Нет
void listFullRooms() const

Описание: Перечисляет все занятые номера в отеле.

Параметры: Нет

Возвращает: Нет
double calculateOccupancy() const

Описание: Рассчитывает коэффициент заполняемости отеля.

Параметры: Нет

Возвращает:

    double: Коэффициент заполняемости отеля.

const OrderedTable<Room>& getRooms() const

Описание: Возвращает константную ссылку на таблицу номеров.

Параметры: Нет

Возвращает:

    const OrderedTable<Room>&: Константная ссылка на таблицу номеров.

OrderedTable<Room>::Iterator getRoomsBegin() const

Описание: Возвращает итератор на начало таблицы номеров.

Параметры: Нет

Возвращает:

    OrderedTable<Room>::Iterator: Итератор на начало таблицы номеров.

OrderedTable<Room>::Iterator getRoomsEnd() const

Описание: Возвращает итератор на конец таблицы номеров.

Параметры: Нет

Возвращает:

    OrderedTable<Room>::Iterator: Итератор на конец таблицы номеров.

Эта документация предоставляет обзор системы управления отелем "Hotel California", ее классов, членов и методов.
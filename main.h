/* Программа представляет собой календарь, в котором есть возможность
 * делать пометки о прошедших днях и составлять планы на будущее.
 *      + создать обычный календарь, который отображает только текущий месяц
 *      - создать окно ошибок:
 *          + количество дней в месяце от 28 до 31
 *          - другие баги...
 *      + добавить возможность сменять месяц.
 *          При нажатии на название месяца всплывает окно со всеми месяцами в году
 *      + добавить возможность сменять год
 *          Аналогично месяцу, количество лет подобрать по интерфейсу
 *      - избавиться от сброса месяца/года при переключении между годом/месяцем
 *      - добавить стрелочки по краям экрана, чтобы можно было перелистывать месяц
 *      - добавить возможность создания записей:
 *          - непосредственно редактирование текста конекретной даты
 *          - кнопоки для добавления, удаления и просмотра всех пометок
 *          - окно с редактированием полей конкретной даты
 *          - пользовательский цвет дня
 *
 *      - разные цвета для будних, выходных и помеченых дней
 *      - сохранение настроек и записей
 *
 *********можно сделать РЕЛИЗ !!!
 *
 *      - ежедневные задачи
 *      - бессрочные планы
 *      - глобальные цели
 *      - план на какой-либо день недели (повторяется еженедельно)
 *      - добавить окно приветствия, которое предлагает рассказать, что
 *      сегодня было, если поля сегодняшнего дня пусты
 *      -
 *
*/
#pragma once

#include <QApplication>
#include <QWidget>
#include <QDesktopWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QDebug>
#include <QVector>
#include <QLabel>
#include <QMessageBox>

#include "basescreen.h"

const QString list_of_days_of_the_week[7] = {"Mon.", "Tues.", "Wed.", "Thurs.", "Fri.", "Sat.", "Sun."};
const QString list_of_the_months[12] = {"January", "February", "March", "April", "May", "June", "July",
                                  "August", "September", "October", "November", "December"};



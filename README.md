# Simple-Graphs
Приложение, которое строит простейшие графики по заданным параметрам.
Реализовывалось в качестве курсовой работы на тему "Использование графики в C++"

Алгоритм программы:
![image](https://user-images.githubusercontent.com/88945775/156938477-a9447d32-ab4c-4cf1-87d2-49a86c673ce5.png)

Из блок-схемы видно, что данная программа строит 5 видов линий на плоскости, для трех из которых существует несколько способов задания уравнения. Для каждого вида линии создается собственное окно для построения, которое считывает необходимые параметры и строит график после нажатия кнопки «Построить».

При запуске приложения, первым можно увидеть окно с пятью кнопками, предоставляющими выбор типа линии, которую мы хотим построить. В блок-схеме это окно выглядит как «Окно выбора 1»
![image](https://user-images.githubusercontent.com/88945775/156938545-1f9342ba-9f59-48fb-a3cb-e528f52504c4.png)

При нажатии на кнопку «Прямая» мы попадаем в следящее окно, представляющее собой выбор из 3-х видов задания прямой на плоскости.
![image](https://user-images.githubusercontent.com/88945775/156938611-ff98b90a-4a7e-411a-9728-4c58b0bba4f3.png)

При нажатии «Общее уравнение» мы попадаем в окно, содержащее 3 поля для ввода, область построения графика и кнопку, по нажатию на которую у нас происходит считывание с полей и построение соответствующего графика.
![image](https://user-images.githubusercontent.com/88945775/156938641-567136bd-4989-4728-8f67-8f688393479f.png)

Если ввести все нулевые значения, либо ввести нулевым поле A или B, то программа откроет окно об ошибке.
![image](https://user-images.githubusercontent.com/88945775/156938659-7c5016ee-9bb5-4e50-b39a-7a6b21df7542.png)

При нажатии «Уравнение в отрезках» мы попадем в аналогичное окно, работающее по аналогичному алгоритму. Отличие от предыдущего окна в том, что в данном случае у нас есть всего 2 поля для ввода. Ошибка будет выводится, если, либо A, либо B будут равны нулю. 
![image](https://user-images.githubusercontent.com/88945775/156938681-be5bd97f-76d4-490b-aafb-2bf04486980a.png)

При нажатии «Уравнение с угловым коэффициентом» у нас снова появится окно аналогичное предыдущим 2-м. От уравнения в отрезках оно отличается только названием полей. Если ввести оба значения равными нулю, то всплывет сообщение с ошибкой, текст которой полностью совпадает с предыдущим.
![image](https://user-images.githubusercontent.com/88945775/156938702-84ffcf0f-cc96-4ebb-b8da-f2b62d8a8738.png)

После нажатия на кнопку «Парабола» мы попадаем в следующее окно с двумя кнопками, представляющими собой выбор задания параболы-в каноническом виде, с симметрией относительно оси Ox и в виде квадратного трехчлена, с симметрией относительно Oy. На блок схеме это окно называется «Окно выбора 2».
![image](https://user-images.githubusercontent.com/88945775/156938737-92ded3ca-c7bb-4b04-a718-2e537de966f1.png)
После нажатия в окне выбора 2 на кнопку «Каноническое уравнение параболы» мы попадем в окно, содержащее одно поле для ввода, widget преобразованный в QCustomPlot для отображения графика и кнопку, после нажатия на которую происходит считывание данных с поля и построение графика
![image](https://user-images.githubusercontent.com/88945775/156938751-8695d777-ac3a-47f7-87b6-a394645b82be.png)

Если в окне выбора 2 нажать на кнопку «Квадратный трехчлен», то попадем в аналогичное предыдущему окно с тремя полями для ввода, widget для вывода графика и кнопкой для считывания данных с полей и построения графика.
![image](https://user-images.githubusercontent.com/88945775/156938791-8aa0c0fc-9ea2-464d-9bde-6622c29bfbf7.png)

Если в окне выбора 1 нажать на «Гипербола», то мы перейдем в окно, аналогичное окну выбора 2 и окну выбора 3. На блок-схеме оно называется «Окно выбора 4». Оно состоит из двух кнопок, означающих 2 вида задания гиперболы- каноническое уравнение гиперболы и уравнение равнобочной гиперболы.
![image](https://user-images.githubusercontent.com/88945775/156938811-80eee035-dc63-4cfc-862a-40fb5e892e97.png)
Если в окне выбора 4 нажать на кнопку «Каноническое уравнение», то мы попадем в окно с двумя полями для ввода, widget преобразованным в QCustomPlot и кнопкой для считывания информации с полей и построения графика.
![image](https://user-images.githubusercontent.com/88945775/156938834-978cbfdd-b435-4855-a425-28560943762b.png)

Если в окне выбора 4 нажать на кнопку «Равнобочная гипербола», то мы попадем в окно с одном полем для ввода, widget преобразованным в QCustomPlot и кнопкой для считывания информации с полей и построения графика. 
Равнобочная гипербола означает гиперболу, у которой значения A и B равны, а асимптотами являются оси координат.
![image](https://user-images.githubusercontent.com/88945775/156938867-189c18ea-5d67-42b2-a7e8-e0fbbef78e76.png)

После нажатия кнопки «Эллипс» в окне выбора 1 мы переходим в другое окно, состоящее из четырех полей для ввода, области построения графика и кнопки, после нажатия на которую информация с полей будет считана и график построен.
Если значения A и B не будут заданы или будут раны нулю, то всплывет сообщение об ошибке, аналогичное всем предыдущим

После нажатия на кнопку «Окружность» в окне выбора 1 мы переходим в другое одно, состоящее из двух полей для ввода, widget для отображения графика и кнопки построения.
![image](https://user-images.githubusercontent.com/88945775/156938926-53753d9b-f4fb-4b3d-bba2-68c7465ddce2.png)


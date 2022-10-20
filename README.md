# Backtracking-Problem-solved
Backtracking algorythm to solve an efficiency problem made with C++.

Un parque nacional decide abrir sus puertas para permitirle a las familias que puedan ir a conocerlo. Luego de abierta la inscripción, un número de familias se anotan para realizar la visita. Debido a la gran demanda de público se decide establecer un número limitado de días durante los cuales se aceptarán visitas por esta temporada. Sabiendo que el parque tiene una capacidad diaria acotada, los guías deben distribuir a los visitantes durante los días disponibles. Para esto, solicita a cada familia que le informe (en orden de preferencia) los días en los cuales preferirían realizar la visita, y cuántas personas conforman el grupo familiar.

Por ejemplo, la familia Pérez tiene 3 miembros, y sus preferencias son [33, 25, 10, 62, 48, 53, 66, 78]. El día 33 es el día preferido para los Pérez, de no ser posible ir el 33, el segundo día preferido es el 25, y así sucesivamente. 

Dado que no todas las personas podrán asistir el día que prefieren, el parque decide crear un bono compensatorio para las familias que no son asignadas al día que eligieron como prioritario.

Objetivo

Nuestro objetivo es diseñar un programa que permita determinar qué familias deberán ser invitadas en cada uno de los días disponibles para minimizar el monto total de los bonos compensatorios, considerando que: todas las familias deben poder visitar el parque en alguno de los días que indicaron como preferidos, y cada familia será invitada un único día.


Datos de entrada

Se sabe que el taller estará abierto 10 días consecutivos y que la disponibilidad diaria es de 30 personas.

El bono compensatorio se aplica únicamente a la familia que no es asignada en el primer día elegido como prioritario y se calcula utilizando la siguiente fórmula:

bono = U$S 25 + (U$S 10 * Grupo Familiar) + (U$S 5 * Dia asignado)

Además tenemos dos grupos de familias para asignar.

Dataset 1: En el primer dataset se anotaron 20 familias para visitar el parque. Cada una de estas familias es muy numerosa en cuanto a cantidad de miembros. Se sabe que el bono mínimo para estas familias es de 625 dólares.

Dataset 2: En el segundo dataset se anotaron 60 familias para visitar el parque. Este dataset tiene más familias que el primero, pero las familias no tienen tantos miembros como en el primer dataset. Se sabe que el bono mínimo para estas familias es de 260 dólares.

En ambos datasets, cada familia eligió entre 3 días de los disponibles en el orden en que prefieren realizar la visita.

La estructura de estos dataset se define mediante las siguientes “columnas” de datos: [id,miembros,dia_0,dia_1,dia_2]


Características de la solución

Se considera válida a una solución si:

No supera el tope de capacidad diaria para ninguno de los días disponibles.

Cada familia es asignada a un único día para realizar la visita.

Todas las familias son asignadas para realizar la visita en algunos de sus días preferidos.

Se considera óptima a una solución si:

Es una solución válida.

Se consigue obtener el mínimo costo total del bono compensatorio.

Consigna

Implementar un programa que obtenga la solución óptima al problema planteado (para ambos datasets), resultando en el cronograma de familias por día y calcule el monto total a disponer en bonos compensatorios. También debería registrar la cantidad de estados visitados durante la exploración.

Plantear e implementar una poda posible al algoritmo implementado en el punto 1). Considerar que para la resolución del segundo dataset probablemente sin poda no se consiga una resolución en un tiempo apropiado.

Realizar un breve informe, donde se incluya un análisis sobre el problema planteado y su resolución por Backtracking indicando:

Árbol de exploración: estado inicial, criterio de ramificación y profundidad del árbol.

Estados: datos almacenados en un estado, cuáles son estados finales y cuáles solución. Restricciones en la generación de estados.

Resultados de la ejecución con y sin poda (cuando esto sea posible).

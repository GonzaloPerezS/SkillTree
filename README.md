# SkillTree

Mi objetivo ha sido crear un sistema parecido al que utilizan muchos videojuegos (mas o menos) con distintas habilidades para un personaje, pero con la condicion de que cada habilidad es de una categoria diferente, por lo que el árbol está dividido en tres ramas: Power, Magic y Stealth.

Cada habilidad es un widget independiente que contiene toda la lógica necesaria para saber si puede desbloquearse o no. Al pulsar sobre una habilidad, el sistema comprueba primero que no esté ya desbloqueada, que el jugador tenga puntos de experiencia disponibles y que la habilidad anterior del árbol ya haya sido comprada. Para ello, cada nodo tiene una variable editable desde el editor llamada PreviousSkill, que permite indicar fácilmente cuál es la habilidad que debe estar desbloqueada antes.

El árbol comienza con 25 puntos de experiencia. Cada vez que se compra una habilidad se consume un punto, se muestra por pantalla cuántos quedan y, cuando llegan a cero, ya no es posible seguir desbloqueando habilidades.

He decidido hacerlo de esta forma porque me parecia lo mas eficiente y reutilizable posible. Además, al ser cada habilidad independiente y configurar las conexiones desde el editor, el sistema es fácil de ampliar y modificar sin tener que cambiar el código cada vez que se añadan nuevas habilidades o ramas al árbol.

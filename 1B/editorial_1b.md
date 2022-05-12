<h2>Subtarea 1</h2>

$a = b$ y $c = d$

Solo hay que saber si $p_a > p_b$.

<h2>Subtarea 2</h2>

$p_i < p_{i-1}\ \forall i \in [2, n]$

Tenemos que $p_x > p_y$ para cada par $(x, y)$ con $x \in [a, b]$ y $y \in [c, d]$. Por tanto, la respuesta es $(b - a + 1) \cdot (d - c + 1)$.

<h2>Subtarea 3</h2>

$n, q \le 300$

En esta subtarea, podemos probar todos los pares $(x, y)$ con $x \in [a, b]$ y $y \in [c, d]$. Cada uno de esos rangos tiene longitud $\mathcal{O}(n)$, por lo que esta solución tiene complejidad temporal $\mathcal{O}(ssq\cdot n^2)$.

---

Para las próximas subtareas, primeramente computaremos todos los pares $(x, y)$ con $x > y$ y $p_x > p_y$. Llamemos a esos pares como *puntos relevantes*.

<h2>Subtarea 4</h2

$q \le 6000$

Digamos $cnt(x, b)$ es la cantidad de *puntos relevantes* $(x, y)$ con $y \le b$.

Entonces, la respuesta a una pregunta $([a, b], [c, d])$ es  $$\displaystyle\sum_{x \in [a, b]} (cnt(x, d) - cnt(x, c - 1))$$

Podemos computar $cnt(x, ?)$ en tiempo $\mathcal{O}(n)$:

$cnt(x, y) = cnt(x, y - 1) + [\ (x, y) \text{ es  relevante }]$. 

De esa manera, se puede responder cada pregunta en tiempo $\mathcal{O}(n)$, quedando en $\mathcal{O}(q \cdot n)$.

---
<h2>Subtarea 6</h2>

Podemos extender la idea de computar la cantidad de puntos con $y \le T$ para ambas coordenadas. Digamos que $s(a, b)$ es la cantidad de  *puntos relevantes* $(x,y)$ con $x \le a; y \le b$.

Hay varias formas de computar $s(?,?)$ en tiempo $\mathcal{O}(n^2)$.sss
1. Una forma, es usando $cnt(?,?)$ de la subtarea anterior. Podemos decir que $s(a, b) = \displaystyle\sum_{x \le a} cnt(x, b)$. Y, naturalmente, podemos computar $s(a,b)$ a partir de valores ya computados:
$s(a,b) = s(a-1,b) + cnt(a,b)$.

2. Otra forma muy conocida, es:
$s(a,b) = s(a-1,b) + s(a,b-1) - s(a-1,b-1) + [(a,b) es relevante]$.

Entonces, la respuesta a una pregunta $([a, b], [c, d])$ es

$$s(c, d) - s(c,b-1) - s(a-1,d) + s(a-1,b-1)$$

Así, podemos responder cada pregunta en tiempo constante, obteniendo complejidad final $\mathcal{O}(n^2 + q)$.



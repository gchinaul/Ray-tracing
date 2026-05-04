# miniRT (Ray tracing) — 42 School

Projet **miniRT** de l’école 42 : implémentation d’un **mini moteur de ray tracing** capable de parser des scènes `.rt` et de rendre une image via **MiniLibX**.

## Sommaire
- [Pré-requis](#pré-requis)
- [Compilation](#compilation)
- [Exécution](#exécution)
- [Format de scène (.rt)](#format-de-scène-rt)
- [Organisation du dépôt](#organisation-du-dépôt)
- [Bonus](#bonus)

## Pré-requis
- **GNU make**
- **clang** ou **gcc**
- Sous Linux : dépendances X11 usuelles pour MiniLibX (selon votre distro)

Le dépôt inclut `minilibx-linux/`.

## Compilation

```bash
make
```
```bash
make bonus
```

Cibles courantes (si disponibles dans votre Makefile) :

```bash
make clean
make fclean
make re
```

## Exécution

```bash
./miniRT maps/mand/<scene>.rt
```
```bash
./miniRT_Bonus maps/bonus/<scene>.rt
```

(Adaptez le chemin de scène selon vos fichiers dans `maps/`.)

## Format de scène (.rt)
Exemple minimal (indicatif) :

```rt
A 0.2 255,255,255
C 0,0,-10 0,0,1 70
L 10,10,-10 0.8 255,255,255
sp 0,0,0 2 255,0,0
```

## Organisation du dépôt

- `Makefile` (racine)
- `ft_printf/` : implémentation personnalisée de `printf` et utilitaires associés
- `gnl/` : `get_next_line` (lecture ligne par ligne)
- `include/` : headers du projet principal (structures, utilitaires, erreurs, parsing, ...)
- `libft/` : bibliothèque utilitaire (libft)
- `maps/` : scènes de test / exemple (`bonus`, `error`, `mand`)
- `minilibx-linux/` : MiniLibX (Linux)
- `Ray-tracing/` : dossiers/fichiers liés à des tests ou modules ray tracing (selon votre organisation)
- `src/` : code source principal (version mandatory)
- `src_bonus/` : code source de la version bonus
- `textures/` : textures utilisées dans le rendu

## Bonus
Si votre projet supporte des fonctionnalités bonus (textures, bump, multi-lights, reflections, etc.), vous pouvez les lister ici.

---

### Auteur
- **gchinaul**

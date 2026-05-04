# miniRT (Ray tracing)

![License](https://img.shields.io/badge/license-MIT-blue.svg)

## Présentation du projet
miniRT est un projet de l'école 42 qui consiste à implémenter un moteur de ray tracing simple. Il permet de créer des images photoréalistes en simulant le comportement de la lumière.

## Caractéristiques
- Rendu de scènes 3D basées sur des modèles simples
- Support pour différentes formes géométriques
- Gestion des lumières et des ombres
- Support pour les matériaux et textures

## Dépendances
- [Minilibx](https://github.com/42Paris/minilibx)
- [Libft](https://github.com/42Paris/libft)

## Instructions de compilation
Pour compiler le projet, utilisez les commandes suivantes : 
```bash
make
```

## Comment exécuter avec un fichier de scène exemple
Pour exécuter le rendu d'une scène, utilisez la commande suivante : 
```bash
./miniRT scene.rt
```

## Structure du projet
- `src/` : Contient le code source
- `include/` : Contient les fichiers d'en-tête
- `scenes/` : Contient les fichiers de scène .rt
- `Makefile` : Fichier pour la compilation

## Comment écrire un exemple de scène .rt simple
Voici un exemple d'une scène minimale : 
```rt
a 0.2
l 1 1 1 0 1 0 0.5
sp 0 0 0 1 255 0 0
```

## Conseils de dépannage
- Assurez-vous que toutes les dépendances sont correctement installées.
- Vérifiez le format du fichier .rt pour toute erreur de syntaxe.
- Consultez le Makefile pour toute configuration erronée.

## Auteurs
- gchinaul

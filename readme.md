# CGI Login Script

## Description

Ce script CGI en C++ permet de gérer l'authentification des utilisateurs. Il extrait le nom d'utilisateur et le mot de passe envoyés via un formulaire POST, les vérifie par rapport à un fichier texte (`data.txt`), et affiche un message de succès ou redirige l'utilisateur en cas d'échec de la connexion.

## Fonctionnalités

- Extraction des données d'identification (`name` et `password`) à partir d'une requête POST.
- Vérification des informations d'identification par rapport à un fichier texte (`data.txt`).
- Affichage d'un message de succès en cas de connexion réussie.
- Redirection vers `index.html` avec un message d'erreur en cas de connexion échouée.

## Prérequis

- Un serveur web configuré pour exécuter des scripts CGI.
- C++ compiler (`g++`).
- Le fichier `data.txt` doit exister dans le même répertoire que le script CGI.

## Structure des fichiers

- `login.cgi` : Le script CGI compilé.
- `index.cpp` : Le code source C++.
- `data.txt` : Le fichier contenant les paires nom d'utilisateur/mot de passe.

## Format du fichier `data.txt`

Le fichier `data.txt` doit contenir les informations d'identification sous le format suivant :


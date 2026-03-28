Improved version of the original project.  Credits for the parallax background: Janelle Grumiaux https://www.linkedin.com/in/janelle-grumiaux-kapahou-kenmoe-33910829b/
Original memory: 414 Mo

# **SHOOT_THEM_UP**

---

## **1. Informations Générales**

**Titre** : ZENIROX 2.0.  
**Genre** : Shoot'em Up.
**Style Visuel** : Pixel Art (particules, explosions dynamiques).  
**Plateforme(s)** : PC.  
**Public cible** : Amateurs de jeux d’arcade et de défis rapides, âgés de 3 ans et plus.  
**Résumé** : La Terre a été attaquée par une planète ennemie appelée Zenirox. Le joueur repousse l'attaque avant de contre-attaquer.

---

## **2. Concept de Base**

- **Gameplay principal** : Le joueur contrôle un vaisseau spatial, détruit des vagues d’ennemis et évite des projectiles et des obstacle pour progresser dans les niveaux.  
- **Objectifs** : Détruire les vagues d'ennemis pour pouvoir tuer le Boss de la planète Zenirox.
  - Court terme : Survivre et accumuler des pièces en détruisant les ennemis.
  - Long terme : Compléter les niveaux, vaincre les boss et sauver la planète.  
- **Déroulement** : Le jeu est divisé en plusieurs niveaux avec une difficulté croissante, chacun se terminant par un combat de boss. Pour terminer le jeu il faut donc tuer le Boss du dernier niveau. 
- **Style de progression** : Défilement vertical automatique, avec des power-ups sur le terrain.

---

## **3. Méchaniques de Jeu**

### **3.1. Contrôle du joueur**
- **Déplacement** : Utilisation des flèches haut et bas du clavier.  
- **Tir** : Tir automatique en maintenant en faisant un clique gauche sur la souris.  
- **Obstacles** : Présence d'astéroïdes qui infligent des dégâts au contact. En mode difficile, des malus divers peuvent apparaître.

### **3.2. Système de Scoring**
- **Score** : Le score est représenté par des pièces et augmente à chaque tir réussi sur un ennemi.
- **Shop** : Possibilité d'acheter des skins avec le score.
  
### **3.3. Power-ups**
1. **Boost d'attaque**
   - Augmente la vitesse de tir, représenté par une pile.
2. **Boosts défensifs** :  
   - Bouclier (barre de vie bleue absorbant la même quantité de dégâts que la barre de vie classique, mais indépendante (ne soigne pas la vie initiale).
   - Coeur: soigne la vie.

### **3.4. Difficulté**
- **Modes de jeu** :  
   - Facile : Le joueur inflige plus de dégâts et les ennemis lui en infligent moins. 
   - Normal : Dégâts infligés et reçus standards. 
   - Hardcore : Les ennemis sont plus lents à tuer et infligent plus de dégâts. Il n'y a plus de powers up. Des malus apparaîssent à la place et fonctionnent comme les power-ups mais sont appliqués aux ennemis plutôt qu'au joueur.

---

## **4. Conception des Ennemis**

### **4.1. Types d’ennemis**
1. **Basique** :  
   - Faible santé, zero mouvement.  
2. **Intermédiaire** :  
   - Mouvements lent, santé moyenne.  
3. **Avancé** :  
   - Déplacement rapide, santé élevée.  

### **4.2. Boss**
Chaque niveau se termine par un boss avec des mécaniques uniques :
- **Tier 1**  
   -  Tire par raffale, très rapidement.
- **Tier Niveau 2**  
   -  Se déplace très rapidement.
- **Tier 3**
   -  Possède un bouclier.
- **Boss final**
   -  Possède toutes les particularités des autres boss.
---

## **5. Progression et Structure**

### **5.1. Niveaux**
1. **Tier 1** : Haute atmosphère terrestre.
   - Ennemi : Boss 1.
     
2. **Tier 2** : Espace.   
   - Ennemi : Boss 2.
     
3. **Tier 3** : Système solaire ennemi.
   - Ennemi : Boss 3.

4. **Boss final** : Haute atmosphère de la planète ennemie.  
   - Ennemi : Boss final.  

### **5.2. Rythme**
-Augmentation du niveau moyen des ennemis à chaque niveau.

---

## **6. Direction Artistique**

### **6.1. Style Visuel**
- Pixel art rétro.  
- Palette de couleurs évoluant selon les niveaux :  
  - Niveau 1 : Tons Terrestre (bleu, vert).  
  - Niveau 2 : Tons spatiaux (bleu).  
  - Niveau 3 : Atmosphère extraterrestre(violet, bleu, rouge).
  - Niveaux 4 : Planète extraterrestre (rose, violet, vert).  

### **6.2. Interface utilisateur**

- **HUD** :  
   - Affichage du score. 
   - Barre de vie du joueur en bas à gauche.
   - Bouton de pause.
   - Niveau actuel.

---

## **7. Direction Audio**

### **7.1. Musique**
- Rythmes électroniques rapides pour les phases d’action.  
- Musique plus lourde et dramatique pour les combats de boss.

### **7.2. Effets sonores**
- Sons distincts pour les tirs, les explosions, et les power-ups.  
- Signal audio pour les attaques spéciales des boss ou les situations dangereuses.  

---

## **8. Systèmes et Outils**

### **8.1. Moteur de Jeu**
- **SFML** 

---

## **9. Monétisation**
1. **Modèle principal** : Jeu premium avec achat unique.  
2. **Contenu additionnel** (DLC) :  
   - Niveaux supplémentaires avec de nouveaux ennemis et boss.  
   - Packs de skins pour le vaisseau.  

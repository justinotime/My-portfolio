const toggle = document.querySelector('#mobile-menu'); /* Targetting navbar toggle */
const menuLinks = document.querySelector('.navbar_menu'); /* Targetting ul class */

// Display Mobile Menu
const mobileMenu = () => {
    toggle.classList.toggle('is-active');
    menuLinks.classList.toggle('active');
}

toggle.addEventListener('click', mobileMenu);
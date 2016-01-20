/*******************************************************************************
* File Name: Vmenos.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "Vmenos.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 Vmenos__PORT == 15 && ((Vmenos__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: Vmenos_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None
*  
*******************************************************************************/
void Vmenos_Write(uint8 value) 
{
    uint8 staticBits = (Vmenos_DR & (uint8)(~Vmenos_MASK));
    Vmenos_DR = staticBits | ((uint8)(value << Vmenos_SHIFT) & Vmenos_MASK);
}


/*******************************************************************************
* Function Name: Vmenos_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Vmenos_DM_STRONG     Strong Drive 
*  Vmenos_DM_OD_HI      Open Drain, Drives High 
*  Vmenos_DM_OD_LO      Open Drain, Drives Low 
*  Vmenos_DM_RES_UP     Resistive Pull Up 
*  Vmenos_DM_RES_DWN    Resistive Pull Down 
*  Vmenos_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Vmenos_DM_DIG_HIZ    High Impedance Digital 
*  Vmenos_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Vmenos_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Vmenos_0, mode);
}


/*******************************************************************************
* Function Name: Vmenos_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro Vmenos_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Vmenos_Read(void) 
{
    return (Vmenos_PS & Vmenos_MASK) >> Vmenos_SHIFT;
}


/*******************************************************************************
* Function Name: Vmenos_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 Vmenos_ReadDataReg(void) 
{
    return (Vmenos_DR & Vmenos_MASK) >> Vmenos_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Vmenos_INTSTAT) 

    /*******************************************************************************
    * Function Name: Vmenos_ClearInterrupt
    ********************************************************************************
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 Vmenos_ClearInterrupt(void) 
    {
        return (Vmenos_INTSTAT & Vmenos_MASK) >> Vmenos_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */